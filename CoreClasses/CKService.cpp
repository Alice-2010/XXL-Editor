#include "CKService.h"
#include "File.h"
#include "KEnvironment.h"
#include "CKLogic.h"
#include "CKNode.h"
#include "CKHook.h"
#include "CKGroup.h"
#include "CKComponent.h"
#include <numbers>

void CKSrvEvent::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	numA = file->readUint16();
	numB = file->readUint16();
	numC = file->readUint16();
	numTotalActions = file->readUint16();
	sequences.resize(numA + numB + numC);
	int ev = 0;
	for (EventSequence &b : sequences) {
		b.numActions = file->readUint8();
		b.bitMask = file->readUint8();
		ev += b.numActions;
	}
	objs.resize(numTotalActions);
	for (auto &obj : objs)
		obj.read(file);
	objInfos.reserve(numTotalActions);
	for (size_t i = 0; i < numTotalActions; i++)
		objInfos.push_back(file->readUint16());

	int16_t nxid = 0;
	evtSeqIDs.resize(sequences.size());
	for (int16_t& id : evtSeqIDs)
		id = nxid++;
	nextSeqID = nxid;

	evtSeqNames.resize(sequences.size());
	for (int i = 0; i < sequences.size(); ++i)
		evtSeqNames[i] = '#' + std::to_string(i);
}

void CKSrvEvent::serialize(KEnvironment * kenv, File * file)
{
	file->writeUint16(numA);
	file->writeUint16(numB);
	file->writeUint16(numC);
	numTotalActions = objs.size();
	file->writeUint16(numTotalActions);
	for (EventSequence &b : sequences) {
		file->writeUint8(b.numActions);
		file->writeUint8(b.bitMask);
	}
	for (auto &obj : objs)
		obj.write(kenv, file);
	for (uint16_t &arg : objInfos)
		file->writeUint16(arg);
}

void CKSrvEvent::onLevelLoaded2(KEnvironment * kenv)
{
	int eventindex = 0;
	for (EventSequence &b : sequences) {
		int str = -1;
		if (b.sector >= -1) {
			str = b.sector;
		}
		else if (b.userFound) {
			if (!b.users.empty()) {
				CKObject* user = b.users[0];
				if (CKFlaggedPath* path = user->dyncast<CKFlaggedPath>()) {
					str = path->usingSector;
				}
				else if (CKSector* kstr = user->dyncast<CKSector>()) {
					str = kstr->strId - 1;
				}
				else if (CKHkLight* hkLight = /*nullptr*/ user->dyncast<CKHkLight>()) {
					CKGrpLight* grpLight = hkLight->lightGrpLight->cast<CKGrpLight>();
					std::vector<Vector3>& points = grpLight->node->cast<CNode>()->geometry->cast<CKParticleGeometry>()->pgPoints;
					int index = points.size() - 1;
					CKHook* hook;
					for (hook = grpLight->childHook.get(); hook; hook = hook->next.get()) {
						if (hook == hkLight)
							break;
						index--;
					}
					assert(hook);
					const Vector3& pnt = points[index];
					int bestSector = -1; float bestDistance = HUGE_VALF;
					for (int sector = 0; sector < kenv->numSectors; sector++) {
						CKMeshKluster* kluster = kenv->sectorObjects[sector].getFirst<CKMeshKluster>();
						for (auto& gnd : kluster->grounds) {
							if (gnd->isSubclassOf<CDynamicGround>())
								continue;
							if (pnt.x >= gnd->aabb.lowCorner.x && pnt.x <= gnd->aabb.highCorner.x
								&& pnt.z >= gnd->aabb.lowCorner.z && pnt.z <= gnd->aabb.highCorner.z)
							{
								float dist = 0.0f;
								if (pnt.y < gnd->aabb.lowCorner.y)
									dist = std::abs(pnt.y - gnd->aabb.lowCorner.y);
								else if (pnt.y > gnd->aabb.highCorner.y)
									dist = std::abs(pnt.y - gnd->aabb.highCorner.y);
								if (dist < bestDistance) {
									bestSector = sector;
									bestDistance = dist;
								}
							}
						}
					}
					str = bestSector;
				}
				else if (CKHook* hook = user->dyncast<CKHook>())
					if (hook->life)
						str = (hook->life->unk1 >> 2) - 1;
			}
		}
		for (int i = 0; i < b.numActions; i++) {
			objs[eventindex + i].bind(kenv, str);
		}
		eventindex += b.numActions;
		b.sector = str;
	}
}

int CKSrvEvent::getAddendumVersion()
{
	return 1;
}

void CKSrvEvent::deserializeAddendum(KEnvironment* kenv, File* file, int version)
{
	uint32_t numEvents = file->readUint32();
	assert(sequences.size() == (size_t)numEvents);
	evtSeqNames.resize(numEvents);
	for (auto& seq : sequences) {
		seq.sector = file->readInt32();
	}
	for (auto& name : evtSeqNames) {
		std::string adname = file->readSizedString<uint16_t>();
		if (!adname.empty())
			name = std::move(adname);
	}
}

void CKSrvEvent::serializeAddendum(KEnvironment* kenv, File* file)
{
	uint32_t numEvents = evtSeqNames.size();
	file->writeUint32(numEvents);
	for (auto& seq : sequences) {
		file->writeInt32(seq.sector);
	}
	for (auto& name : evtSeqNames) {
		file->writeSizedString<uint16_t>(name);
	}
}

void CKSrvBeacon::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	struct BitReader {
		File *file;
		uint8_t byte, bit;
		BitReader(File *file) : file(file), bit(8) {}
		bool readBit() {
			if (bit >= 8) {
				byte = file->readUint8();
				bit = 0;
			}
			bool v = byte & (1 << bit);
			bit++;
			return v;
		}
	};
	unk1 = file->readUint8();
	uint32_t numHandlers = file->readUint32();
	handlers.resize(numHandlers);
	for (Handler &handler : handlers) {
		handler.unk2a = file->readUint8();
		handler.numBits = file->readUint8();
		handler.handlerIndex = file->readUint8();
		handler.handlerId = file->readUint8();
		handler.persistent = file->readUint8();
		if(kenv->version >= kenv->KVERSION_XXL2)
			handler.x2respawn = file->readUint8();
		handler.object = kenv->readObjRef<CKObject>(file);
	}
	uint32_t numSectors = file->readUint32();
	beaconSectors.resize(numSectors);
	for (auto it = beaconSectors.rbegin(); it != beaconSectors.rend(); it++) {
		BeaconSector &bs = *it;
		bs.numUsedBings = file->readUint32();
		bs.numBings = file->readUint32();
		bs.beaconArraySize = file->readUint32();
		uint32_t numBits = file->readUint32();
		BitReader bread(file);
		for (uint32_t i = 0; i < numBits; i++)
			bs.bits.push_back(bread.readBit());
		uint32_t numBeaconKlusters;
		if (kenv->version >= kenv->KVERSION_XXL2 || kenv->isRemaster) // xxl1 Romaster extended it to 32-bit
			numBeaconKlusters = file->readUint32();
		else
			numBeaconKlusters = file->readUint8();
		for (uint32_t i = 0; i < numBeaconKlusters; i++)
			bs._bkids.push_back(file->readUint32());
	}
}

void CKSrvBeacon::serialize(KEnvironment * kenv, File * file)
{
	struct BitWriter {
		File *file;
		uint8_t byte, bit;
		BitWriter(File *file) : file(file), byte(0), bit(0) {}
		void writeBit(bool v) {
			if (bit >= 8) {
				file->writeUint8(byte);
				byte = 0;
				bit = 0;
			}
			if(v)
				byte |= (1 << bit);
			bit++;
		}
		void end() {
			if(bit)
				file->writeUint8(byte);
		}
	};
	file->writeUint8(unk1);
	file->writeUint32(handlers.size());
	for (Handler &handler : handlers) {
		file->writeUint8(handler.unk2a);
		file->writeUint8(handler.numBits);
		file->writeUint8(handler.handlerIndex);
		file->writeUint8(handler.handlerId);
		file->writeUint8(handler.persistent);
		if (kenv->version >= kenv->KVERSION_XXL2)
			file->writeUint8(handler.x2respawn);
		kenv->writeObjRef(file, handler.object);
	}
	file->writeUint32(beaconSectors.size());
	for (auto it = beaconSectors.rbegin(); it != beaconSectors.rend(); it++) {
		BeaconSector &bs = *it;
		file->writeUint32(bs.numUsedBings);
		file->writeUint32(bs.numBings);
		file->writeUint32(bs.beaconArraySize);
		file->writeUint32(bs.bits.size());
		BitWriter bwrite(file);
		for (uint32_t i = 0; i < bs.bits.size(); i++)
			bwrite.writeBit(bs.bits[i]);
		bwrite.end();
		if (kenv->version >= kenv->KVERSION_XXL2 || kenv->isRemaster) // xxl1 Romaster extended it to 32-bit
			file->writeUint32(bs.beaconKlusters.size());
		else
			file->writeUint8(bs.beaconKlusters.size());
		for (auto &ref : bs.beaconKlusters)
			kenv->writeObjRef(file, ref);
	}
}

void CKSrvBeacon::onLevelLoaded(KEnvironment * kenv)
{
	int str = -1;
	for (BeaconSector &bs : beaconSectors) {
		for (uint32_t id : bs._bkids)
			bs.beaconKlusters.push_back(kenv->getObjRef<CKBeaconKluster>(id, str));
		str++;
	}
}

void CKSrvBeacon::removeBeacon(int sectorIndex, int klusterIndex, int bingIndex, int beaconIndex)
{
	BeaconSector& bsec = beaconSectors[sectorIndex];
	CKBeaconKluster* bkluster = bsec.beaconKlusters[klusterIndex].get();
	CKBeaconKluster::Bing& bbing = bkluster->bings[bingIndex];

	// remove bits
	int beaNumBits = handlers[bbing.handlerIndex].numBits;
	int beax = bbing.bitIndex + beaNumBits * beaconIndex;
	auto it = bsec.bits.begin() + beax;
	bsec.bits.erase(it, it + beaNumBits);

	// remove beacon
	bbing.beacons.erase(bbing.beacons.begin() + beaconIndex);
	bsec.beaconArraySize -= 8;

	// relocate bitIndex of next bings
	bingIndex++;
	CKBeaconKluster* nextBkluster = bkluster;
	while (nextBkluster) {
		for (; bingIndex < nextBkluster->bings.size(); bingIndex++) {
			CKBeaconKluster::Bing& bing = nextBkluster->bings[bingIndex];
			if (bing.active && bing.bitIndex > 0)
				bing.bitIndex -= beaNumBits;
		}
		bingIndex = 0;
		nextBkluster = nextBkluster->nextKluster.get();
	}

	// beacon is now fully removed
	// we may still want to clean empty klusters/bings
	
	if (bbing.beacons.empty()) {
		bbing = {};
		bkluster->numUsedBings -= 1;
		bsec.numUsedBings -= 1;
	}
}

void CKSrvBeacon::addHandler(CKObject* handler, uint8_t numBits, uint8_t handlerId, uint8_t persistent, uint8_t respawn)
{
	size_t numHands = handlers.size();
	CKSrvBeacon::Handler h = { 8, numBits, numHands, handlerId, persistent, respawn, handler };
	handlers.push_back(h);

	// add new bing at every kluster
	for (auto& bsec : beaconSectors) {
		bsec.numBings += bsec.beaconKlusters.size();
		for (auto& bk : bsec.beaconKlusters) {
			bk->bings.emplace_back();
		}
	}
}

void CKSrvBeacon::enableBing(int sectorIndex, int klusterIndex, int bingIndex)
{
	auto& bsec = beaconSectors[sectorIndex];
	auto& bkluster = bsec.beaconKlusters[klusterIndex];
	auto& bing = bkluster->bings[bingIndex];
	auto& hs = handlers[bingIndex];

	if (bing.active)
		return;

	// find bit position
	int bx = 0;
	for (auto& k : bsec.beaconKlusters) {
		for (auto& g : k->bings) {
			if (&g == &bing)
				goto fnd;
			bx += g.numBits * g.beacons.size();
		}
	}
fnd:
	bing.active = true;
	bing.handler = hs.object.get();
	bing.unk2a = 8; // Always 8, but in XXL1 Greece, hs.unk2a is 2 for some reason, even though bing.unk2a is 8. Using bing.unk2a=2 will make the crates except the last one disappear.
	bing.numBits = hs.numBits;
	bing.handlerId = hs.handlerId;
	bing.sectorIndex = sectorIndex;
	bing.klusterIndex = klusterIndex;
	bing.handlerIndex = hs.handlerIndex;
	bing.bitIndex = bx;
	bing.unk6 = 0x128c;	// some class id?

	bkluster->numUsedBings++;
	bsec.numUsedBings++;
}

int CKSrvBeacon::addBeacon(int sectorIndex, int klusterIndex, int handlerIndex, const SBeacon& beacon)
{
	enableBing(sectorIndex, klusterIndex, handlerIndex);
	auto& bsec = beaconSectors[sectorIndex];
	auto* bkluster = bsec.beaconKlusters[klusterIndex].get();
	auto& bing = bkluster->bings[handlerIndex];
	auto& hs = handlers[handlerIndex];

	int beaconIndex = (int)bing.beacons.size();
	bing.beacons.push_back(beacon);
	bsec.beaconArraySize += 8;

	// add bits
	int beaNumBits = hs.numBits;
	int beax = bing.bitIndex + beaNumBits * beaconIndex;
	bsec.bits.insert(bsec.bits.begin() + beax, beaNumBits, true);
	for (int i = 0; i < beaNumBits; i++)
		bsec.bits[beax + i] = (beacon.params >> i) & 1;

	// relocate bitIndex of next bings
	handlerIndex++;
	while (bkluster) {
		for (; handlerIndex < bkluster->bings.size(); handlerIndex++) {
			CKBeaconKluster::Bing& bing = bkluster->bings[handlerIndex];
			if (bing.active)
				bing.bitIndex += beaNumBits;
		}
		handlerIndex = 0;
		bkluster = bkluster->nextKluster.get();
	}
	
	return beaconIndex;
}

std::pair<int, int> CKSrvBeacon::addBeaconToNearestKluster(KEnvironment& kenv, int sectorIndex, int handlerIndex, const SBeacon& beacon)
{
	BoundingSphere beaconSphere = getBeaconSphere(beacon, handlerIndex);
	const auto& beaconSector = beaconSectors[sectorIndex];
	int nearestKlusterIndex = -1;
	float nearestKlusterCenterDistance = std::numeric_limits<float>::max();
	for (int klusterIndex = 0; klusterIndex < beaconSector.beaconKlusters.size(); ++klusterIndex) {
		const auto& kluster = beaconSector.beaconKlusters[klusterIndex];
		const float klusterCenterDistance = (kluster->bounds.center - beaconSphere.center).len3();
		auto klusterSphere = kluster->bounds;
		klusterSphere.radius = std::max(klusterSphere.radius, 2.5f); // make the kluster radius bigger if too small when testing, to increase chance of intersecting
		if (klusterSphere.intersectsWithSphere(beaconSphere) && klusterCenterDistance < nearestKlusterCenterDistance) {
			nearestKlusterCenterDistance = klusterCenterDistance;
			nearestKlusterIndex = klusterIndex;
		}
	}
	if (nearestKlusterIndex >= 0) {
		const int beaconIndex = addBeacon(sectorIndex, nearestKlusterIndex, handlerIndex, beacon);
		return { nearestKlusterIndex, beaconIndex };
	}
	else {
		const int klusterIndex = addKluster(kenv, sectorIndex);
		const int beaconIndex = addBeacon(sectorIndex, klusterIndex, handlerIndex, beacon);
		return { klusterIndex, beaconIndex };
	}
}

void CKSrvBeacon::cleanEmptyKlusters(KEnvironment& kenv, int sectorIndex)
{
	auto& beaconSector = beaconSectors[sectorIndex];
	auto& klusterList = beaconSector.beaconKlusters;
	int newKlusterIndex = 0;
	for (auto& klusterRef : klusterList) {
		auto* kluster = klusterRef.get();
		if (kluster->empty()) {
			// remove the empty kluster
			klusterRef = nullptr;
			beaconSector.numBings -= kluster->bings.size();

			CKLevel* klevel = kenv.levelObjects.getFirst<CKLevel>();
			CKSector* ksector = klevel->sectors[sectorIndex].get();
			if (ksector->beaconKluster.get() == kluster) {
				ksector->beaconKluster = kluster->nextKluster.get();
			}
			else {
				for (CKBeaconKluster* candKluster = ksector->beaconKluster.get(); candKluster; candKluster = candKluster->nextKluster.get()) {
					if (candKluster->nextKluster.get() == kluster) {
						candKluster->nextKluster = kluster->nextKluster;
						break;
					}
				}
			}

			kenv.removeObject(kluster);
		}
		else {
			// update kluster indices in the bings
			for (auto& bing : kluster->bings) {
				if (bing.active) {
					bing.klusterIndex = newKlusterIndex;
				}
			}
			newKlusterIndex += 1;
		}
	}
	std::erase_if(klusterList, [](auto& ref) {return !ref; });
}

void CKSrvBeacon::updateKlusterBounds(CKBeaconKluster* kluster)
{
	BoundingSphere bounds = kluster->bounds;
	bool first = true;
	for (auto& bing : kluster->bings) {
		for (auto& beacon : bing.beacons) {
			BoundingSphere beaconSphere = getBeaconSphere(beacon, bing.handlerIndex);
			if (first) {
				bounds = beaconSphere;
				first = false;
			}
			else
				bounds.merge(beaconSphere);
		}
	}
	kluster->bounds = bounds;
}

std::vector<bool>::iterator CKSrvBeacon::getBeaconBitIterator(int sectorIndex, int klusterIndex, int bingIndex, int beaconIndex)
{
	auto& beaconSector = beaconSectors[sectorIndex];
	auto& bing = beaconSector.beaconKlusters[klusterIndex]->bings[bingIndex];
	const int bitIndex = bing.bitIndex + beaconIndex * bing.numBits;
	return beaconSector.bits.begin() + bitIndex;
}

BoundingSphere CKSrvBeacon::getBeaconSphere(const SBeacon& beacon, int handlerIndex) const
{
	CKObject* handlerObj = handlers[handlerIndex].object.get();
	static constexpr float boxRadius = std::numbers::sqrt3_v<float> / 2.0f; // radius of sphere enclosing a 1x1x1 box
	if (handlerObj->isSubclassOf<CKCrateCpnt>()) {
		const int numCrates = beacon.params & 7;
		// strange equation
		const float radius = boxRadius * (1 + numCrates);
		const Vector3 position = beacon.getPosition() + Vector3(0.0f, numCrates / 2.0f, 0.0f);
		return BoundingSphere(position, radius);
		// smaller, more precise one:
		//Vector3 lowCorner = beacon.getPosition() + Vector3(-0.5f, 0.0f, -0.5f);
		//Vector3 uppCorner = lowCorner + Vector3(1.0f, (float)numCrates, 1.0f);
		//return BoundingSphere((lowCorner + uppCorner) * 0.5f, (uppCorner - lowCorner).len3() * 0.5f);
	}
	if (handlers[handlerIndex].handlerId == 0x10) {
		// Merchant
		return BoundingSphere(beacon.getPosition(), 2 * boxRadius);
	}
	return BoundingSphere(beacon.getPosition(), boxRadius);
}

int CKSrvBeacon::addKluster(KEnvironment& kenv, int sectorIndex)
{
	auto& strObjList = (sectorIndex == 0) ? kenv.levelObjects : kenv.sectorObjects[sectorIndex-1];
	BeaconSector& bsec = beaconSectors[sectorIndex];

	CKBeaconKluster* kluster = kenv.createObject<CKBeaconKluster>(sectorIndex-1);
	int klusterIndex = (int)bsec.beaconKlusters.size();
	bsec.beaconKlusters.push_back(kluster);
	bsec.numBings += handlers.size();

	auto numBkObjs = strObjList.getClassType<CKBeaconKluster>().objects.size();
	if (numBkObjs >= 2) {
		strObjList.getObject<CKBeaconKluster>(numBkObjs - 2)->nextKluster = kluster;
	}

	CKLevel* klevel = kenv.levelObjects.getFirst<CKLevel>();
	if (klevel->sectors[sectorIndex]->beaconKluster.get() == nullptr)
		klevel->sectors[sectorIndex]->beaconKluster = strObjList.getFirst<CKBeaconKluster>();

	kluster->numUsedBings = 0;
	kluster->bings.resize(handlers.size());
	return klusterIndex;
}


void CKSrvCollision::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	uint16_t numWhat = file->readUint16();
	huh = file->readUint8();
	for (auto &ref : dynBSphereProjectiles)
		ref = kenv->readObjRef<CKSceneNode>(file);
	objs.resize(numWhat);
	for (auto &vec : objs) {
		vec.resize(file->readUint8());
		for (auto &ref : vec)
			ref = kenv->readObjRef<CKObject>(file);
	}
	uint16_t unk1 = file->readUint16();
	uint16_t unk2 = file->readUint16();
	objs2.resize(unk1);
	for (auto &ref : objs2) {
		ref = kenv->readObjRef<CKObject>(file);
	}
	bings.resize(unk2);
	for (Bing &bing : bings) {
		bing.v1 = file->readUint16();
		bing.obj1 = kenv->readObjRef<CKObject>(file);
		bing.obj2 = kenv->readObjRef<CKObject>(file);
		bing.b1 = file->readUint16();
		bing.b2 = file->readUint16();
		bing.v2 = file->readUint8();
		for (uint16_t &u : bing.aa)
			u = file->readUint16();
	}
	inactiveList = file->readUint16();
	activeList = file->readUint16();
}

void CKSrvCollision::serialize(KEnvironment * kenv, File * file)
{
	file->writeUint16(objs.size());
	file->writeUint8(huh);
	for (auto &ref : dynBSphereProjectiles)
		kenv->writeObjRef(file, ref);
	for (auto &vec : objs) {
		file->writeUint8(vec.size());
		for (auto &ref : vec)
			kenv->writeObjRef<CKObject>(file, ref);
	}
	file->writeUint16((uint16_t)objs2.size());
	file->writeUint16((uint16_t)bings.size());
	for (auto &ref : objs2)
		kenv->writeObjRef(file, ref);
	for (Bing &bing : bings) {
		file->writeUint16(bing.v1);
		kenv->writeObjRef(file, bing.obj1);
		kenv->writeObjRef(file, bing.obj2);
		file->writeUint16(bing.b1);
		file->writeUint16(bing.b2);
		file->writeUint8(bing.v2);
		for (uint16_t &u : bing.aa)
			file->writeUint16(u);
	}
	file->writeUint16(inactiveList);
	file->writeUint16(activeList);
}

uint16_t CKSrvCollision::addOrGetHandler(CKObject* handler) {
	if (!handler)
		return 0xFFFF;
	auto it = std::find_if(objs2.begin(), objs2.end(), [handler](auto& ref) {return ref.get() == handler; });
	if (it != objs2.end())
		return (uint16_t)(it - objs2.begin());
	uint16_t index = (uint16_t)objs2.size();
	objs2.emplace_back(handler);
	return index;
}

CKSrvCollision::CollIndex CKSrvCollision::addCollision(CKObject* handler1, CKBoundingShape* shape1, CKObject* handler2, CKBoundingShape* shape2) {
	CollIndex index = (CollIndex)bings.size();
	auto& coll = bings.emplace_back();
	coll.obj1 = shape1;
	coll.obj2 = shape2;
	coll.b1 = addOrGetHandler(handler1);
	coll.b2 = addOrGetHandler(handler2);
	coll.aa[0] = inactiveList;
	inactiveList = index;
	return index;
}

void CKSrvCollision::setParent(CollIndex colIndex, CollIndex parentIndex)
{
	auto& ccol = bings[colIndex];
	auto& pcol = bings[parentIndex];
	assert((ccol.v1 & 16) == 0);
	assert((pcol.v1 & 16) == 0);
	ccol.aa[2] = parentIndex;
	ccol.v1 = 0xE;
	pcol.v1 = 1;
}

void CKSrvPathFinding::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	nodes.resize(file->readUint32());
	for (auto &ref : nodes)
		ref = kenv->readObjRef<CKPFGraphNode>(file, -1);
	if (kenv->version >= kenv->KVERSION_ARTHUR) {
		for (auto &ref : arQuadTreeBranches)
			ref = kenv->readObjRef<CKObject>(file);
		for (auto &val : arQTBInts)
			val = file->readUint32();
	}
	if(kenv->version >= kenv->KVERSION_XXL2)
		x2flt = file->readFloat();
}

void CKSrvPathFinding::serialize(KEnvironment * kenv, File * file)
{
	file->writeUint32(nodes.size());
	for (auto &ref : nodes)
		kenv->writeObjRef(file, ref);
	if (kenv->version >= kenv->KVERSION_ARTHUR) {
		for (auto &ref : arQuadTreeBranches)
			kenv->writeObjRef(file, ref);
		for (auto &val : arQTBInts)
			file->writeUint32(val);
	}
	if (kenv->version >= kenv->KVERSION_XXL2)
		file->writeFloat(x2flt);
}

void CKSrvMarker::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	lists.resize(file->readUint32());
	for (std::vector<Marker> &list : lists) {
		list.resize(file->readUint32());
		for (Marker &marker : list) {
			for (float &f : marker.position)
				f = file->readFloat();
			marker.orientation1 = file->readUint8();
			marker.orientation2 = file->readUint8();
			marker.val3 = file->readUint16();
		}
	}
}

void CKSrvMarker::serialize(KEnvironment * kenv, File * file)
{
	file->writeUint32(lists.size());
	for (std::vector<Marker> &list : lists) {
		file->writeUint32(list.size());
		for (Marker &marker : list) {
			for (float &f : marker.position)
				file->writeFloat(f);
			file->writeUint8(marker.orientation1);
			file->writeUint8(marker.orientation2);
			file->writeUint16(marker.val3);
		}
	}
}

int CKSrvMarker::getAddendumVersion()
{
	return 1;
}

void CKSrvMarker::deserializeAddendum(KEnvironment* kenv, File* file, int version)
{
	uint32_t totalMarkers = 0;
	for (auto& list : lists)
		totalMarkers += (uint32_t)list.size();
	uint32_t totalMarkersFile = file->readUint32();
	assert(totalMarkers == totalMarkersFile);
	for (auto& list : lists) {
		for (auto& marker : list) {
			marker.name = file->readSizedString<uint16_t>();
		}
	}
}

void CKSrvMarker::serializeAddendum(KEnvironment* kenv, File* file)
{
	uint32_t totalMarkers = 0;
	for (auto& list : lists)
		totalMarkers += (uint32_t)list.size();
	file->writeUint32(totalMarkers);
	for (auto& list : lists) {
		for (auto& marker : list) {
			file->writeSizedString<uint16_t>(marker.name);
		}
	}
}

void CKSrvDetector::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	uint16_t numA = file->readUint16();
	uint16_t numB = file->readUint16();
	uint16_t numC = file->readUint16();
	uint16_t numD = file->readUint16();
	uint16_t numE = file->readUint16();
	uint16_t numAABB = file->readUint16();
	uint16_t numSpheres = file->readUint16();
	uint16_t numRectangles = file->readUint16();
	uint16_t numRefs = file->readUint16();
	numJ = file->readUint16();

	aaBoundingBoxes.resize(numAABB);
	for (auto &aabb : aaBoundingBoxes)
		aabb.deserialize(file);

	spheres.resize(numSpheres);
	for (auto &sph : spheres)
		sph.deserialize(file, true);

	rectangles.resize(numRectangles);
	for (auto &h : rectangles) {
		for (float &f : h.center)
			f = file->readFloat();
		h.length1 = file->readFloat();
		h.length2 = file->readFloat();
		h.direction = file->readUint8();
	}

	for (auto detvec : { std::make_pair(&aDetectors, &numA), std::make_pair(&bDetectors, &numB), std::make_pair(&cDetectors, &numC),
						 std::make_pair(&dDetectors, &numD), std::make_pair(&eDetectors, &numE) })
	{
		detvec.first->resize(*detvec.second);
		for (auto &det : *detvec.first) {
			det.shapeIndex = file->readUint16();
			det.nodeIndex = file->readUint16();
			det.flags = file->readUint16();
			det.eventSeqIndex.read(kenv, file, this);
		}
	}

	nodes.resize(numRefs);
	for (auto &ref : nodes)
		ref = kenv->readObjRef<CKSceneNode>(file, -1);

	aabbNames.resize(aaBoundingBoxes.size());
	sphNames.resize(spheres.size());
	rectNames.resize(rectangles.size());
}

void CKSrvDetector::serialize(KEnvironment * kenv, File * file)
{
	file->writeUint16((uint16_t)aDetectors.size());
	file->writeUint16((uint16_t)bDetectors.size());
	file->writeUint16((uint16_t)cDetectors.size());
	file->writeUint16((uint16_t)dDetectors.size());
	file->writeUint16((uint16_t)eDetectors.size());
	file->writeUint16((uint16_t)aaBoundingBoxes.size());
	file->writeUint16((uint16_t)spheres.size());
	file->writeUint16((uint16_t)rectangles.size());
	file->writeUint16((uint16_t)nodes.size());
	file->writeUint16(numJ);

	for (auto &aabb : aaBoundingBoxes)
		aabb.serialize(file);

	for (auto &sph : spheres)
		sph.serialize(file, true);

	for (auto &h : rectangles) {
		for (float &f : h.center)
			file->writeFloat(f);
		file->writeFloat(h.length1);
		file->writeFloat(h.length2);
		file->writeUint8(h.direction);
	}

	for (auto detvec : { &aDetectors, &bDetectors, &cDetectors, &dDetectors, &eDetectors }) {
		for (const auto &det : *detvec) {
			file->writeUint16(det.shapeIndex);
			file->writeUint16(det.nodeIndex);
			file->writeUint16(det.flags);
			det.eventSeqIndex.write(kenv, file);
		}
	}

	for (auto &ref : nodes)
		kenv->writeObjRef(file, ref);

}

int CKSrvDetector::getAddendumVersion()
{
	return 1;
}

void CKSrvDetector::deserializeAddendum(KEnvironment* kenv, File* file, int version)
{
	uint32_t numAabbNames = file->readUint32();
	uint32_t numSphNames = file->readUint32();
	uint32_t numRectNames = file->readUint32();
	assert(aabbNames.size() == numAabbNames);
	assert(sphNames.size() == numSphNames);
	assert(rectNames.size() == numRectNames);
	for (auto& name : aabbNames)
		name = file->readSizedString<uint16_t>();
	for (auto& name : sphNames)
		name = file->readSizedString<uint16_t>();
	for (auto& name : rectNames)
		name = file->readSizedString<uint16_t>();
}

void CKSrvDetector::serializeAddendum(KEnvironment* kenv, File* file)
{
	assert(aabbNames.size() == aaBoundingBoxes.size());
	assert(sphNames.size() == spheres.size());
	assert(rectNames.size() == rectangles.size());
	file->writeUint32((uint32_t)aabbNames.size());
	file->writeUint32((uint32_t)sphNames.size());
	file->writeUint32((uint32_t)rectNames.size());
	for (auto& name : aabbNames)
		file->writeSizedString<uint16_t>(name);
	for (auto& name : sphNames)
		file->writeSizedString<uint16_t>(name);
	for (auto& name : rectNames)
		file->writeSizedString<uint16_t>(name);
}

void CKSrvCinematic::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	cineScenes.resize(file->readUint32());
	for (auto &scene : cineScenes)
		scene = kenv->readObjRef<CKCinematicScene>(file);
	cineBillboard1 = kenv->readObjRef<CKObject>(file);
	cineBillboard2 = kenv->readObjRef<CKObject>(file);
	cineBillboard3 = kenv->readObjRef<CKObject>(file);
	if (kenv->version >= KEnvironment::KVERSION_XXL2) {
		arObjectList.resize(file->readUint32());
		for (auto& ref : arObjectList)
			ref = kenv->readObjRef<CKObject>(file);
		if (kenv->version < KEnvironment::KVERSION_ARTHUR)
			arGlobalValue = file->readInt32();
	}
}

void CKSrvCinematic::serialize(KEnvironment * kenv, File * file)
{
	file->writeUint32((uint32_t)cineScenes.size());
	for (auto &scene : cineScenes)
		kenv->writeObjRef(file, scene);
	kenv->writeObjRef(file, cineBillboard1);
	kenv->writeObjRef(file, cineBillboard2);
	kenv->writeObjRef(file, cineBillboard3);
	if (kenv->version >= KEnvironment::KVERSION_XXL2) {
		file->writeUint32((uint32_t)arObjectList.size());
		for (auto& ref : arObjectList)
			kenv->writeObjRef(file, ref);
		if (kenv->version < KEnvironment::KVERSION_ARTHUR)
			file->writeInt32(arGlobalValue);
	}
}

void CKSrvCinematic::deserializeGlobal(KEnvironment* kenv, File* file, size_t length)
{
	arGlobalValue = file->readInt32();
}

void CKSrvTrigger::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	rootDomain = kenv->readObjRef<CKTriggerDomain>(file);
	numTotalActions = file->readUint32();
	numTotalEventCmpData = file->readUint32();
	if (kenv->version >= kenv->KVERSION_SPYRO || (kenv->version == kenv->KVERSION_OLYMPIC && kenv->platform == kenv->PLATFORM_X360)) {
		spTriggers.resize(file->readUint32());
		for (auto& p : spTriggers) {
			p.first = kenv->readObjRef<CKTrigger>(file);
			p.second = file->readSizedString<uint16_t>();
		}
	}
}

void CKSrvTrigger::serialize(KEnvironment * kenv, File * file)
{
	numTotalActions = 0;
	numTotalEventCmpData = 0;
	for (CKObject* obj : kenv->levelObjects.getClassType<CKTrigger>().objects) {
		CKTrigger* trig = (CKTrigger*)obj;
		numTotalActions += (uint32_t)trig->actions.size();
	}
	for (CKObject* obj : kenv->levelObjects.getClassType<CKComparedData>().objects) {
		CKComparedData* dat = (CKComparedData*)obj;
		if (dat->getDataType() == 2)
			numTotalEventCmpData += 1;
	}

	kenv->writeObjRef(file, rootDomain);
	file->writeUint32(numTotalActions);
	file->writeUint32(numTotalEventCmpData);
	if (kenv->version >= kenv->KVERSION_SPYRO || (kenv->version == kenv->KVERSION_OLYMPIC && kenv->platform == kenv->PLATFORM_X360)) {
		file->writeUint32(spTriggers.size());
		for (auto& p : spTriggers) {
			kenv->writeObjRef(file, p.first);
			file->writeSizedString<uint16_t>(p.second);
		}
	}
}

void CKSrvCamera::reflectMembers2(MemberListener & r, KEnvironment *kenv)
{
	CKReflectableService::reflectMembers2(r, kenv);
	if (kenv->version == KEnvironment::KVERSION_XXL1) {
		r.reflect(scamUnk0, "scamUnk0");
		r.reflect(scamCam, "scamCam");
		r.reflect(scamCamstr, "scamCamstr");
		if (kenv->isRemaster)
			r.reflect(scamCamfixtrack, "scamCamfixtrack");
		else
			r.reflect(scamCamfixtrack[0], "scamCamfixtrack");
		scamCameraInst.reflectMembers2(r, kenv);
		if (kenv->isRemaster)
			r.reflect(scamAnimNode, "scamAnimNode");
		else
			r.reflect(scamAnimNode[0], "scamAnimNode");
		r.reflect(scamUnk15, "scamUnk15");
		r.reflect(scamUnk16, "scamUnk16");
		r.reflect(scamUnk17, "scamUnk17");
		r.reflect(scamUnk18, "scamUnk18");
		r.reflect(scamUnk19, "scamUnk19");
		r.reflect(scamUnk20, "scamUnk20");
		r.reflect(scamUnk21, "scamUnk21");
		r.reflect(scamUnk22, "scamUnk22");
		r.reflect(scamSphere1, "scamSphere1");
		r.reflect(scamSphere2, "scamSphere2");
		r.reflect(scamUnk25, "scamUnk25");
		r.reflect(scamUnk26, "scamUnk26");
		r.reflect(scamUnk27, "scamUnk27");
		r.reflect(scamUnk28, "scamUnk28");
		r.reflect(scamUnk29, "scamUnk29");
		r.reflect(scamUnk30, "scamUnk30");
		r.reflect(scamUnk31, "scamUnk31");
		r.reflect(scamUnk32, "scamUnk32");
		r.reflect(scamUnk33, "scamUnk33");
		r.reflect(scamUnk34, "scamUnk34");
		r.reflect(scamUnk35, "scamUnk35");
		r.reflect(scamUnk36, "scamUnk36");
		if (kenv->isRemaster) {
			r.reflect(scamRoma1, "scamRoma1");
			r.reflect(scamRoma2, "scamRoma2");
		}
	}
	else if (kenv->version >= KEnvironment::KVERSION_XXL2) {
		r.reflect(scamCam, "scamCam");
		r.reflectSize<uint32_t>(x2scCameraSectors, "x2scCameraSectors_size");
		r.enterArray("x2scCameraSectors");
		for (auto& vec : x2scCameraSectors) {
			r.enterStruct("vec");
			r.reflectSize<uint32_t>(vec, "vec_size");
			r.reflect(vec, "vec");
			r.leaveStruct();
			r.incrementIndex();
		}
		r.leaveArray();
		if (kenv->version == KEnvironment::KVERSION_ARTHUR)
			r.reflect(scamAnimNodeArFix, "scamAnimNodeArFix");
		else
			r.reflect(scamAnimNode[0], "scamAnimNode");
		r.reflect(x2scUnk1, "x2scUnk1");
		r.reflect(x2scUnk2, "x2scUnk2");
		r.reflect(x2scUnk3, "x2scUnk3");
		r.reflect(x2scUnk4, "x2scUnk4");
		r.reflect(x2scUnk5, "x2scUnk5");
		r.reflect(x2scUnk6, "x2scUnk6");
		r.reflect(x2scUnk7, "x2scUnk7");
		r.reflect(scamSphere1, "scamSphere1");
		r.reflect(scamSphere2, "scamSphere2");
		r.reflect(x2scUnk8, "x2scUnk8");

		if (kenv->version >= KEnvironment::KVERSION_ARTHUR) {
			r.reflect(og103Floats, "og103Floats");
		}

		if (kenv->version < KEnvironment::KVERSION_ARTHUR) {
			r.reflect(x2scUnkMass, "x2scUnkMass");
		}
		else {
			r.reflect(ogUnkMass, "ogUnkMass");
		}
		r.reflect(x2scUnkA, "x2scUnkA");
		r.reflect(x2scUnkB, "x2scUnkB");
		r.reflect(x2scUnkC, "x2scUnkC");
		if (kenv->version <= KEnvironment::KVERSION_XXL2) {
			r.reflectSize<uint32_t>(x2scQuakeDatas, "x2scQuakeDatas_size");
			r.reflect(x2scQuakeDatas, "x2scQuakeDatas");
		}
		else if (kenv->version >= KEnvironment::KVERSION_ARTHUR) {
			r.reflectSize<uint32_t>(ogQuakeDatas, "ogQuakeDatas_size");
			r.enterArray("ogQuakeDatas");
			for (auto& qd : ogQuakeDatas) {
				r.enterStruct("qd");
				r.reflect(qd.quakeCpnt, "quakeCpnt");
				r.reflectSize<uint32_t>(qd.quakeCpntUpdaters, "quakeCpntUpdaters_size");
				r.reflect(qd.quakeCpntUpdaters, "quakeCpntUpdaters");
				r.leaveStruct();
			}
			r.leaveArray();
			if (kenv->version >= KEnvironment::KVERSION_OLYMPIC) {
				r.reflect(ogUnk1, "ogUnk1");
				r.reflect(ogUnk2, "ogUnk2");
				r.reflect(ogUnk3, "ogUnk3");
			}
		}
	}
}

void CKServiceLife::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	firstBundle = kenv->readObjRef<CKBundle>(file);
}

void CKServiceLife::serialize(KEnvironment * kenv, File * file)
{
	kenv->writeObjRef(file, firstBundle);
}

void CKServiceLife::addBundle(CKBundle* bundle)
{
	bundle->next = firstBundle;
	firstBundle = bundle;
}

void CKServiceLife::removeBundle(CKBundle* bundle)
{
	if (firstBundle.get() == bundle) {
		firstBundle = bundle->next;
		bundle->next = nullptr;
	}
	else {
		for (CKBundle* b = firstBundle.get(); b; b = b->next.get()) {
			if (b->next.get() == bundle) {
				b->next = bundle->next;
				bundle->next = nullptr;
				break;
			}
		}
	}
}

void CKSrvSekensor::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	sekens.resize(file->readUint32());
	for (auto &ref : sekens)
		ref = kenv->readObjRef<CKSekens>(file);
}

void CKSrvSekensor::serialize(KEnvironment * kenv, File * file)
{
	file->writeUint32(sekens.size());
	for (auto &ref : sekens)
		kenv->writeObjRef(file, ref);
}

void CKSrvSekensor::deserializeGlobal(KEnvironment* kenv, File* file, size_t length)
{
	ogGlobFltVec.resize(file->readUint32());
	for (float& flt : ogGlobFltVec)
		flt = file->readFloat();
	ogGlobUnkFlt1 = file->readFloat();
	ogGlobUnkFlt2 = file->readFloat();
}

void CKSrvAvoidance::deserialize(KEnvironment * kenv, File * file, size_t length)
{
	if (kenv->version == KEnvironment::KVERSION_XXL1)
		avoidValue = file->readFloat();
}

void CKSrvAvoidance::serialize(KEnvironment * kenv, File * file)
{
	if (kenv->version == KEnvironment::KVERSION_XXL1)
		file->writeFloat(avoidValue);
}

void CKSrvShadow::deserialize(KEnvironment* kenv, File* file, size_t length)
{
	shadUnk1 = file->readUint32();
	shadUnk2 = file->readUint32();
	shadNode = kenv->readObjRef<CNode>(file);
	shadGeometry = kenv->readObjRef<CKParticleGeometry>(file);
	shadTexture = file->readSizedString<uint16_t>();
	shadValues.resize(file->readUint8());
	for (auto& a : shadValues)
		for (float& f : a)
			f = file->readFloat();
	shadUnk3 = file->readUint8();
	shadUnk4 = file->readUint8();
	shadUnk5 = file->readFloat();
}

void CKSrvShadow::serialize(KEnvironment* kenv, File* file)
{
	file->writeUint32(shadUnk1);
	file->writeUint32(shadUnk2);
	kenv->writeObjRef(file, shadNode);
	kenv->writeObjRef(file, shadGeometry);
	file->writeSizedString<uint16_t>(shadTexture);
	file->writeUint8(shadValues.size()); // truncation
	for (auto& a : shadValues)
		for (float& f : a)
			file->writeFloat(f);
	file->writeUint8(shadUnk3);
	file->writeUint8(shadUnk4);
	file->writeFloat(shadUnk5);
}

void CKSrvFx::deserialize(KEnvironment* kenv, File* file, size_t length)
{
	if (kenv->version == KEnvironment::KVERSION_XXL1) {
		fxTypes.resize(file->readUint8());
		for (auto& fxt : fxTypes) {
			fxt.clsFullId = file->readUint32();
			fxt.numInstances = file->readUint8();
			fxt.startIndex = file->readUint8();
		}
		fxInstances.resize(file->readUint8());
		for (auto& fxi : fxInstances)
			fxi = kenv->readObjRef<CKObject>(file);
	}
	else if (kenv->version >= KEnvironment::KVERSION_XXL2) {
		fxTypes2.resize(file->readUint8());
		for (auto& fxt : fxTypes2) {
			fxt.fxLists.resize(file->readUint8());
			for (auto& [id, vec] : fxt.fxLists) {
				vec.resize(file->readUint8());
				id = file->readUint8();
				for (auto& ref : vec)
					ref = kenv->readObjRef<CKObject>(file);
			}
			fxt.clsFullId = file->readInt32();
		}
		particlesList.resize(file->readUint32());
		for (auto& ref : particlesList)
			ref = kenv->readObjRef<CKObject>(file);
		if (kenv->version < KEnvironment::KVERSION_ARTHUR) {
			nullList.resize(file->readUint32());
			for (auto& ref : nullList)
				ref = kenv->readObjRef<CKObject>(file);
		}
		specialFxObjects.resize(file->readUint8());
		for (auto& ref : specialFxObjects)
			ref = kenv->readObjRef<CKObject>(file);
	}
}

void CKSrvFx::serialize(KEnvironment* kenv, File* file)
{
	if (kenv->version == KEnvironment::KVERSION_XXL1) {
		file->writeUint8(fxTypes.size());
		for (auto& fxt : fxTypes) {
			file->writeUint32(fxt.clsFullId);
			file->writeUint8(fxt.numInstances);
			file->writeUint8(fxt.startIndex);
		}
		file->writeUint8(fxInstances.size());
		for (auto& fxi : fxInstances)
			kenv->writeObjRef<CKObject>(file, fxi);
	}
	else if (kenv->version >= KEnvironment::KVERSION_XXL2) {
		file->writeUint8((uint8_t)fxTypes2.size());
		for (auto& fxt : fxTypes2) {
			file->writeUint8((uint8_t)fxt.fxLists.size());
			for (auto& [id, vec] : fxt.fxLists) {
				file->writeUint8((uint8_t)vec.size());
				file->writeUint8(id);
				for (auto& ref : vec)
					kenv->writeObjRef(file, ref);
			}
			file->writeInt32(fxt.clsFullId);
		}
		file->writeUint32((uint32_t)particlesList.size());
		for (auto& ref : particlesList)
			kenv->writeObjRef(file, ref);
		if (kenv->version < KEnvironment::KVERSION_ARTHUR) {
			file->writeUint32((uint32_t)nullList.size());
			for (auto& ref : nullList)
				kenv->writeObjRef(file, ref);
		}
		file->writeUint8((uint8_t)specialFxObjects.size());
		for (auto& ref : specialFxObjects)
			kenv->writeObjRef(file, ref);
	}
}

void CKSrvProjectiles::deserialize(KEnvironment* kenv, File* file, size_t length)
{
	uint8_t count = file->readUint8();
	projectiles.resize(count);
	for (auto& ref : projectiles)
		ref = kenv->readObjRef<CKProjectileTypeBase>(file);
}

void CKSrvProjectiles::serialize(KEnvironment* kenv, File* file)
{
	file->writeUint8((uint8_t)projectiles.size());
	for (auto& ref : projectiles)
		kenv->writeObjRef(file, ref);
}

void CKSrvCounter::deserialize(KEnvironment* kenv, File* file, size_t length)
{
	integerCounters.resize(file->readUint32());
	for (auto& ref : integerCounters)
		ref = kenv->readObjRef<CKIntegerCounter>(file);
	timeCounters.resize(file->readUint32());
	for (auto& ref : timeCounters)
		ref = kenv->readObjRef<CKTimeCounter>(file);
}

void CKSrvCounter::serialize(KEnvironment* kenv, File* file)
{
	file->writeUint32((uint32_t)integerCounters.size());
	for (auto& ref : integerCounters)
		kenv->writeObjRef(file, ref);
	file->writeUint32((uint32_t)timeCounters.size());
	for (auto& ref : timeCounters)
		kenv->writeObjRef(file, ref);
}

void CKSrvDetect::deserialize(KEnvironment* kenv, File* file, size_t length)
{
	movables.resize(file->readUint32());
	for (auto& ref : movables)
		ref = kenv->readObjRef<CKDetectedMovable>(file);
}

void CKSrvDetect::serialize(KEnvironment* kenv, File* file)
{
	file->writeUint32((uint32_t)movables.size());
	for (auto& ref : movables)
		kenv->writeObjRef(file, ref);
}

void CKSrvMusic::deserialize(KEnvironment* kenv, File* file, size_t length)
{
	playLists.resize(file->readUint32());
	for (auto& ref : playLists)
		ref = kenv->readObjRef<CKMusicPlayList>(file);
	smByte = file->readUint8();
	detectors.resize(file->readUint32());
	for (auto& ref : detectors)
		ref = kenv->readObjRef<CKDetectorMusic>(file);
}

void CKSrvMusic::serialize(KEnvironment* kenv, File* file)
{
	file->writeUint32((uint32_t)playLists.size());
	for (auto& ref : playLists)
		kenv->writeObjRef(file, ref);
	file->writeUint8(smByte);
	file->writeUint32((uint32_t)detectors.size());
	for (auto& ref : detectors)
		kenv->writeObjRef(file, ref);
}

void CKSrvMusic::deserializeGlobal(KEnvironment* kenv, File* file, size_t length)
{
	ogGlobByte = file->readUint8();
}
