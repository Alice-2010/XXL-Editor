#include "ClassRegister.h"
#include "KEnvironment.h"

#include "CoreClasses/CKManager.h"
#include "CoreClasses/CKHook.h"
#include "CoreClasses/CKGroup.h"
#include "CoreClasses/CKComponent.h"
#include "CoreClasses/CKCamera.h"
#include "CoreClasses/CKCinematicNode.h"
#include "CoreClasses/CKDictionary.h"
#include "CoreClasses/CKGeometry.h"
#include "CoreClasses/CKNode.h"
#include "CoreClasses/CKLogic.h"
#include "CoreClasses/CKGraphical.h"
#include "GameClasses/CKGameX1.h"
#include "GameClasses/CKGameX2.h"
#include "GameClasses/CKGameOG.h"

void ClassRegister::registerClassesForXXL1PC(KEnvironment& kenv)
{
	// XXL1 PC/GC Original+Romaster

	using namespace GameX1;

	kenv.addFactory<CKServiceManager>();
	kenv.addFactory<CKGraphic>();
	kenv.addFactory<CKSoundManager>();

	kenv.addFactory<CKServiceLife>();
	kenv.addFactory<CKSrvCollision>();
	kenv.addFactory<CKSrvCamera>();
	kenv.addFactory<CKSrvCinematic>();
	kenv.addFactory<CKSrvEvent>();
	kenv.addFactory<CKSrvPathFinding>();
	kenv.addFactory<CKSrvDetector>();
	kenv.addFactory<CKSrvMarker>();
	kenv.addFactory<CKSrvAvoidance>();
	kenv.addFactory<CKSrvSekensor>();
	kenv.addFactory<CKSrvBeacon>();
	kenv.addFactory<CKSrvShadow>();
	kenv.addFactory<CKSrvProjectiles>();
	kenv.addFactory<CKSrvFx>();

	kenv.addFactory<CKHkPressionStone>();
	kenv.addFactory<CKHkAsterix>();
	kenv.addFactory<CKHkObelix>();
	kenv.addFactory<CKHkIdefix>();
	kenv.addFactory<CKHkMachinegun>();
	kenv.addFactory<CKHkTorch>();
	kenv.addFactory<CKHkHearth>();
	kenv.addFactory<CKHkDrawbridge>();
	kenv.addFactory<CKHkMegaAshtray>();
	kenv.addFactory<CKHkBoat>();
	kenv.addFactory<CKHkCorkscrew>();
	kenv.addFactory<CKHkTurnstile>();
	kenv.addFactory<CKHkLifter>();
	kenv.addFactory<CKHkActivator>();
	kenv.addFactory<CKHkRotaryBeam>();
	kenv.addFactory<CKHkLightPillar>();
	kenv.addFactory<CKHkWind>();
	kenv.addFactory<CKHkJumpingRoman>();
	kenv.addFactory<CKHkWaterJet>();
	kenv.addFactory<CKHkPowderKeg>();
	kenv.addFactory<CKHkTriangularTurtle>();
	kenv.addFactory<CKHkBasicEnemy>();
	kenv.addFactory<CKHkRomanArcher>();
	kenv.addFactory<CKHkAnimatedCharacter>();
	kenv.addFactory<CKHkSwingDoor>();
	kenv.addFactory<CKHkSlideDoor>();
	kenv.addFactory<CKHkCrumblyZone>();
	kenv.addFactory<CKHkHelmetCage>();
	kenv.addFactory<CKHkSquareTurtle>();
	kenv.addFactory<CKHkTeleBridge>();
	kenv.addFactory<CKHkCrate>();
	kenv.addFactory<CKHkBasicBonus>();
	kenv.addFactory<CKHkDonutTurtle>();
	kenv.addFactory<CKHkPyramidalTurtle>();
	kenv.addFactory<CKHkRollingStone>();
	kenv.addFactory<CKHkInterfaceBase>();
	kenv.addFactory<CKHkInterfaceEvolution>();
	kenv.addFactory<CKHkCatapult>();
	kenv.addFactory<CKHkInterfacePause>();
	kenv.addFactory<CKHkInterfaceInGame>();
	kenv.addFactory<CKHkInterfaceOption>();
	kenv.addFactory<CKHkInterfaceMain>();
	kenv.addFactory<CKHkInterfaceLoadSave>();
	kenv.addFactory<CKHkInterfaceCloth>();
	kenv.addFactory<CKHkInterfaceShop>();
	kenv.addFactory<CKHkPushPullAsterix>();
	kenv.addFactory<CKHkBasicEnemyLeader>();
	kenv.addFactory<CKHkTelepher>();
	kenv.addFactory<CKHkTowedTelepher>();
	kenv.addFactory<CKHkBumper>();
	kenv.addFactory<CKHkClueMan>();
	kenv.addFactory<CKHkSky>();
	kenv.addFactory<CKHkRocketRoman>();
	kenv.addFactory<CKHkJetPackRoman>();
	kenv.addFactory<CKHkWildBoar>();
	kenv.addFactory<CKHkAsterixShop>();
	kenv.addFactory<CKHkWater>();
	kenv.addFactory<CKHkMobileTower>();
	kenv.addFactory<CKHkBoss>();
	kenv.addFactory<CKHkInterfaceDemo>();
	kenv.addFactory<CKHkWaterFx>();
	kenv.addFactory<CKHkHighGrass>();
	kenv.addFactory<CKHkWaterFall>();
	kenv.addFactory<CKHkInterfaceGallery>();
	kenv.addFactory<CKHkTrioCatapult>();
	kenv.addFactory<CKHkObelixCatapult>();
	kenv.addFactory<CKHkInterfaceOpening>();
	kenv.addFactory<CKHkAsterixCheckpoint>();
	kenv.addFactory<CKHkBonusSpitter>();
	kenv.addFactory<CKHkLight>();
	kenv.addFactory<CKHkParkourSteleAsterix>();

	kenv.addFactory<CKHkAsterixLife>();
	kenv.addFactory<CKHkBoatLife>();
	kenv.addFactory<CKHkObelixLife>();
	kenv.addFactory<CKHkMecaLife>();
	kenv.addFactory<CKHkIdefixLife>();
	kenv.addFactory<CKHkEnemyLife>();
	kenv.addFactory<CKHkTriangularTurtleLife>();
	kenv.addFactory<CKHkAnimatedCharacterLife>();
	kenv.addFactory<CKHkSquareTurtleLife>();
	kenv.addFactory<CKHkDonutTurtleLife>();
	kenv.addFactory<CKHkPyramidalTurtleLife>();
	kenv.addFactory<CKHkCatapultLife>();
	kenv.addFactory<CKHkSkyLife>();
	kenv.addFactory<CKHkWaterLife>();
	kenv.addFactory<CKHkBossLife>();
	kenv.addFactory<CKHkWaterFxLife>();
	kenv.addFactory<CKHkAsterixCheckpointLife>();
	kenv.addFactory<CKHkWaterFallLife>();

	kenv.addFactory<CKGroupRoot>();
	kenv.addFactory<CKGrpMeca>();
	kenv.addFactory<CKGrpTrio>();
	kenv.addFactory<CKGrpBoat>();
	kenv.addFactory<CKGrpSquadEnemy>();
	kenv.addFactory<CKGrpEnemy>();
	kenv.addFactory<CKGrpPoolSquad>();
	kenv.addFactory<CKGrpWalkingCharacter>();
	kenv.addFactory<CKGrpBonus>();
	kenv.addFactory<CKGrpFrontEnd>();
	kenv.addFactory<CKGrpCatapult>();
	kenv.addFactory<CKGrpMap>();
	kenv.addFactory<CKGrpStorageStd>();
	kenv.addFactory<CKGrpCrate>();
	kenv.addFactory<CKGrpBonusPool>();
	kenv.addFactory<CKGrpAsterixBonusPool>();
	kenv.addFactory<CKGrpSquadJetPack>();
	kenv.addFactory<CKGrpWildBoarPool>();
	kenv.addFactory<CKGrpAsterixCheckpoint>();
	kenv.addFactory<CKGrpBonusSpitter>();
	kenv.addFactory<CKGrpLight>();

	kenv.addFactory<CKGrpTrioLife>();
	kenv.addFactory<CKGrpMecaLife>();
	kenv.addFactory<CKGrpBonusLife>();
	kenv.addFactory<CKGrpMapLife>();
	kenv.addFactory<CKGrpEnemyLife>();
	kenv.addFactory<CKGrpAsterixCheckpointLife>();

	kenv.addFactory<CKGrpMecaCpntAsterix>();
	kenv.addFactory<CKCrateCpnt>();
	kenv.addFactory<CKBasicEnemyCpnt>();
	kenv.addFactory<CKBasicEnemyLeaderCpnt>();
	kenv.addFactory<CKJumpingRomanCpnt>();
	kenv.addFactory<CKRomanArcherCpnt>();
	kenv.addFactory<CKShadowCpnt>();
	kenv.addFactory<CKRocketRomanCpnt>();
	kenv.addFactory<CKBonusCpnt>();
	kenv.addFactory<CKJetPackRomanCpnt>();
	kenv.addFactory<CKWildBoarCpnt>();
	kenv.addFactory<CKMobileTowerCpnt>();
	kenv.addFactory<CKTriangularTurtleCpnt>();
	kenv.addFactory<CKSquareTurtleCpnt>();
	kenv.addFactory<CKDonutTurtleCpnt>();
	kenv.addFactory<CKPyramidalTurtleCpnt>();

	kenv.addFactory<CKCamera>();
	kenv.addFactory<CKCameraRigidTrack>();
	kenv.addFactory<CKCameraClassicTrack>();
	kenv.addFactory<CKCameraPathTrack>();
	kenv.addFactory<CKCameraFixTrack>();
	kenv.addFactory<CKCameraAxisTrack>();
	kenv.addFactory<CKCameraSpyTrack>();
	kenv.addFactory<CKCameraPassivePathTrack>();

	kenv.addFactory<CKLogicalAnd>();
	kenv.addFactory<CKLogicalOr>();
	kenv.addFactory<CKPlayAnimCinematicBloc>();
	kenv.addFactory<CKPathFindingCinematicBloc>();
	kenv.addFactory<CKFlaggedPathCinematicBloc>();
	kenv.addFactory<CKGroupBlocCinematicBloc>();
	kenv.addFactory<CKAttachObjectsCinematicBloc>();
	kenv.addFactory<CKStreamCinematicBloc>();
	kenv.addFactory<CKRandLogicalDoor>();
	kenv.addFactory<CKParticleCinematicBloc>();
	kenv.addFactory<CKStreamAloneCinematicBloc>();
	kenv.addFactory<CKStreamGroupBlocCinematicBloc>();
	kenv.addFactory<CKManageEventCinematicBloc>();
	kenv.addFactory<CKManagerEventStopCinematicBloc>();
	kenv.addFactory<CKStartDoor>();
	kenv.addFactory<CKSekensorCinematicBloc>();
	kenv.addFactory<CKDisplayPictureCinematicBloc>();
	kenv.addFactory<CKManageCameraCinematicBloc>();
	kenv.addFactory<CKStartEventCinematicBloc>();
	kenv.addFactory<CKSkyCinematicBloc>();
	kenv.addFactory<CKLightningCinematicBloc>();
	kenv.addFactory<CKPlaySoundCinematicBloc>();
	kenv.addFactory<CKPauseCinematicBloc>();
	kenv.addFactory<CKTeleportCinematicBloc>();
	kenv.addFactory<CKEndDoor>();

	kenv.addFactory<CTextureDictionary>();
	kenv.addFactory<CAnimationDictionary>();
	kenv.addFactory<CKSoundDictionary>();
	kenv.addFactory<CKSoundDictionaryID>();

	kenv.addFactory<CKParticleGeometry>();
	kenv.addFactory<CKGeometry>();
	kenv.addFactory<CKSkinGeometry>();

	kenv.addFactory<CSGRootNode>();
	kenv.addFactory<CSGSectorRoot>();
	kenv.addFactory<CNode>();
	kenv.addFactory<CKDynBSphereProjectile>();
	kenv.addFactory<CSGBranch>();
	kenv.addFactory<CGlowNodeFx>();
	kenv.addFactory<CClone>();
	kenv.addFactory<CKBoundingSphere>();
	kenv.addFactory<CKDynamicBoundingSphere>();
	kenv.addFactory<CKAABB>();
	kenv.addFactory<CKOBB>();
	kenv.addFactory<CParticlesNodeFx>();
	kenv.addFactory<CAnimatedNode>();
	kenv.addFactory<CAnimatedClone>();
	kenv.addFactory<CKAACylinder>();
	kenv.addFactory<CSkyNodeFx>();
	kenv.addFactory<CFogBoxNodeFx>();
	kenv.addFactory<CTrailNodeFx>();

	kenv.addFactory<CKPFGraphTransition>();
	kenv.addFactory<CKBundle>();
	kenv.addFactory<CKSector>();
	kenv.addFactory<CKLevel>();
	kenv.addFactory<CKCameraSector>();
	kenv.addFactory<CKCoreManager>();
	kenv.addFactory<CKSpline4>();
	kenv.addFactory<CKChoreoKey>();
	kenv.addFactory<CKPFGraphNode>();
	kenv.addFactory<CKSas>();
	kenv.addFactory<CGround>();
	kenv.addFactory<CDynamicGround>();
	kenv.addFactory<CWall>();
	kenv.addFactory<CKFlaggedPath>();
	kenv.addFactory<CKMsgAction>();
	kenv.addFactory<CKChoreography>();
	kenv.addFactory<CKLine>();
	kenv.addFactory<CKSpline4L>();
	kenv.addFactory<CKCinematicScene>();
	kenv.addFactory<CKCinematicSceneData>();
	kenv.addFactory<CKDefaultGameManager>();
	kenv.addFactory<CKAsterixGameManager>();
	kenv.addFactory<CKAsterixSlideFP>();
	kenv.addFactory<CLocManager>();
	kenv.addFactory<CKSekens>();
	kenv.addFactory<CKMeshKluster>();
	kenv.addFactory<CKBeaconKluster>();
	kenv.addFactory<CKProjectileTypeScrap>();
	kenv.addFactory<CKProjectileTypeAsterixBomb>();
	kenv.addFactory<CKProjectileTypeBallisticPFX>();
	kenv.addFactory<CKFlashNode2dFx>();
	kenv.addFactory<CKElectricArcNodeFx>();
	kenv.addFactory<CKQuadNodeFx>();
	kenv.addFactory<CKLightningObjectNodeFx>();
	kenv.addFactory<CKFilterNode2dFx>();
	kenv.addFactory<CKExplosionNodeFx>();

	kenv.addFactory<CCloneManager>();
	kenv.addFactory<CAnimationManager>();
	kenv.addFactory<CManager2d>();
	kenv.addFactory<CMenuManager>();
	kenv.addFactory<CContainer2d>();
	kenv.addFactory<CScene2d>();
	kenv.addFactory<CMessageBox2d>();
	kenv.addFactory<CText2d>();
	kenv.addFactory<CColorTextButton2d>();
	kenv.addFactory<CBillboard2d>();
	kenv.addFactory<CBillboard2dList>();
	kenv.addFactory<CBillboardButton2d>();
}

void ClassRegister::registerClassesForXXL1Console(KEnvironment& kenv)
{
	// XXL1 PS2

	using namespace GameX1;

	kenv.addFactory<CKServiceManager>();

	kenv.addFactory<CKSrvCollision>();
	kenv.addFactory<CKSrvCinematic>();
	//kenv.addFactory<CKSrvEvent>();
	kenv.addFactory<CKSrvPathFinding>();
	kenv.addFactory<CKSrvDetector>();
	kenv.addFactory<CKSrvMarker>();
	kenv.addFactory<CKSrvBeacon>();
	kenv.addFactory<CKSrvShadow>();
	kenv.addFactory<CKSrvFx>();

	kenv.addFactory<CKHkPressionStone>();
	kenv.addFactory<CKHkAsterix>();
	kenv.addFactory<CKHkObelix>();
	kenv.addFactory<CKHkIdefix>();
	kenv.addFactory<CKHkMachinegun>();
	kenv.addFactory<CKHkTorch>();
	kenv.addFactory<CKHkHearth>();
	kenv.addFactory<CKHkDrawbridge>();
	kenv.addFactory<CKHkMegaAshtray>();
	kenv.addFactory<CKHkBoat>();
	kenv.addFactory<CKHkCorkscrew>();
	kenv.addFactory<CKHkTurnstile>();
	kenv.addFactory<CKHkLifter>();
	kenv.addFactory<CKHkActivator>();
	kenv.addFactory<CKHkRotaryBeam>();
	kenv.addFactory<CKHkLightPillar>();
	kenv.addFactory<CKHkWind>();
	kenv.addFactory<CKHkJumpingRoman>();
	kenv.addFactory<CKHkWaterJet>();
	kenv.addFactory<CKHkPowderKeg>();
	kenv.addFactory<CKHkTriangularTurtle>();
	kenv.addFactory<CKHkBasicEnemy>();
	kenv.addFactory<CKHkRomanArcher>();
	kenv.addFactory<CKHkAnimatedCharacter>();
	kenv.addFactory<CKHkSwingDoor>();
	kenv.addFactory<CKHkSlideDoor>();
	kenv.addFactory<CKHkCrumblyZone>();
	kenv.addFactory<CKHkHelmetCage>();
	kenv.addFactory<CKHkSquareTurtle>();
	kenv.addFactory<CKHkTeleBridge>();
	kenv.addFactory<CKHkCrate>();
	kenv.addFactory<CKHkBasicBonus>();
	kenv.addFactory<CKHkDonutTurtle>();
	kenv.addFactory<CKHkPyramidalTurtle>();
	kenv.addFactory<CKHkRollingStone>();
	kenv.addFactory<CKHkInterfaceBase>();
	kenv.addFactory<CKHkInterfaceEvolution>();
	kenv.addFactory<CKHkCatapult>();
	kenv.addFactory<CKHkInterfacePause>();
	kenv.addFactory<CKHkInterfaceInGame>();
	kenv.addFactory<CKHkInterfaceOption>();
	kenv.addFactory<CKHkInterfaceMain>();
	kenv.addFactory<CKHkInterfaceLoadSave>();
	kenv.addFactory<CKHkInterfaceCloth>();
	kenv.addFactory<CKHkInterfaceShop>();
	kenv.addFactory<CKHkPushPullAsterix>();
	kenv.addFactory<CKHkBasicEnemyLeader>();
	kenv.addFactory<CKHkTelepher>();
	kenv.addFactory<CKHkTowedTelepher>();
	kenv.addFactory<CKHkBumper>();
	kenv.addFactory<CKHkClueMan>();
	kenv.addFactory<CKHkSky>();
	kenv.addFactory<CKHkRocketRoman>();
	kenv.addFactory<CKHkJetPackRoman>();
	kenv.addFactory<CKHkWildBoar>();
	kenv.addFactory<CKHkAsterixShop>();
	kenv.addFactory<CKHkWater>();
	kenv.addFactory<CKHkMobileTower>();
	kenv.addFactory<CKHkBoss>();
	kenv.addFactory<CKHkInterfaceDemo>();
	kenv.addFactory<CKHkWaterFx>();
	kenv.addFactory<CKHkHighGrass>();
	kenv.addFactory<CKHkWaterFall>();
	kenv.addFactory<CKHkInterfaceGallery>();
	kenv.addFactory<CKHkTrioCatapult>();
	kenv.addFactory<CKHkObelixCatapult>();
	kenv.addFactory<CKHkInterfaceOpening>();
	kenv.addFactory<CKHkAsterixCheckpoint>();
	kenv.addFactory<CKHkBonusSpitter>();
	kenv.addFactory<CKHkLight>();

	kenv.addFactory<CKHkAsterixLife>();
	kenv.addFactory<CKHkBoatLife>();
	kenv.addFactory<CKHkObelixLife>();
	kenv.addFactory<CKHkMecaLife>();
	kenv.addFactory<CKHkIdefixLife>();
	kenv.addFactory<CKHkEnemyLife>();
	kenv.addFactory<CKHkTriangularTurtleLife>();
	kenv.addFactory<CKHkAnimatedCharacterLife>();
	kenv.addFactory<CKHkSquareTurtleLife>();
	kenv.addFactory<CKHkDonutTurtleLife>();
	kenv.addFactory<CKHkPyramidalTurtleLife>();
	kenv.addFactory<CKHkCatapultLife>();
	kenv.addFactory<CKHkSkyLife>();
	kenv.addFactory<CKHkWaterLife>();
	kenv.addFactory<CKHkBossLife>();
	kenv.addFactory<CKHkWaterFxLife>();
	kenv.addFactory<CKHkAsterixCheckpointLife>();
	kenv.addFactory<CKHkWaterFallLife>();

	kenv.addFactory<CKGroupRoot>();
	kenv.addFactory<CKGrpMeca>();
	kenv.addFactory<CKGrpTrio>();
	kenv.addFactory<CKGrpBoat>();
	kenv.addFactory<CKGrpSquadEnemy>();
	kenv.addFactory<CKGrpEnemy>();
	kenv.addFactory<CKGrpPoolSquad>();
	kenv.addFactory<CKGrpWalkingCharacter>();
	kenv.addFactory<CKGrpBonus>();
	kenv.addFactory<CKGrpFrontEnd>();
	kenv.addFactory<CKGrpCatapult>();
	kenv.addFactory<CKGrpMap>();
	kenv.addFactory<CKGrpStorageStd>();
	kenv.addFactory<CKGrpCrate>();
	kenv.addFactory<CKGrpBonusPool>();
	kenv.addFactory<CKGrpAsterixBonusPool>();
	kenv.addFactory<CKGrpSquadJetPack>();
	kenv.addFactory<CKGrpWildBoarPool>();
	kenv.addFactory<CKGrpAsterixCheckpoint>();
	kenv.addFactory<CKGrpBonusSpitter>();
	kenv.addFactory<CKGrpLight>();

	kenv.addFactory<CKGrpTrioLife>();
	kenv.addFactory<CKGrpMecaLife>();
	kenv.addFactory<CKGrpBonusLife>();
	kenv.addFactory<CKGrpMapLife>();
	kenv.addFactory<CKGrpEnemyLife>();
	kenv.addFactory<CKGrpAsterixCheckpointLife>();

	kenv.addFactory<CKCrateCpnt>();
	kenv.addFactory<CKBasicEnemyCpnt>();
	kenv.addFactory<CKBasicEnemyLeaderCpnt>();
	kenv.addFactory<CKJumpingRomanCpnt>();
	kenv.addFactory<CKRomanArcherCpnt>();
	kenv.addFactory<CKShadowCpnt>();
	kenv.addFactory<CKRocketRomanCpnt>();
	kenv.addFactory<CKJetPackRomanCpnt>();
	kenv.addFactory<CKMobileTowerCpnt>();
	kenv.addFactory<CKTriangularTurtleCpnt>();
	kenv.addFactory<CKSquareTurtleCpnt>();
	kenv.addFactory<CKDonutTurtleCpnt>();
	kenv.addFactory<CKPyramidalTurtleCpnt>();

	//kenv.addFactory<CKCinematicBloc>();
	//kenv.addFactory<CKCinematicDoor>();
	kenv.addFactory<CKLogicalAnd>();
	kenv.addFactory<CKLogicalOr>();
	kenv.addFactory<CKPlayAnimCinematicBloc>();
	kenv.addFactory<CKPathFindingCinematicBloc>();
	kenv.addFactory<CKFlaggedPathCinematicBloc>();
	kenv.addFactory<CKGroupBlocCinematicBloc>();
	kenv.addFactory<CKAttachObjectsCinematicBloc>();
	kenv.addFactory<CKStreamCinematicBloc>();
	kenv.addFactory<CKRandLogicalDoor>();
	kenv.addFactory<CKParticleCinematicBloc>();
	kenv.addFactory<CKStreamAloneCinematicBloc>();
	kenv.addFactory<CKStreamGroupBlocCinematicBloc>();
	kenv.addFactory<CKManageEventCinematicBloc>();
	kenv.addFactory<CKManagerEventStopCinematicBloc>();
	kenv.addFactory<CKStartDoor>();
	kenv.addFactory<CKSekensorCinematicBloc>();
	kenv.addFactory<CKDisplayPictureCinematicBloc>();
	kenv.addFactory<CKManageCameraCinematicBloc>();
	kenv.addFactory<CKStartEventCinematicBloc>();
	kenv.addFactory<CKSkyCinematicBloc>();
	kenv.addFactory<CKLightningCinematicBloc>();
	kenv.addFactory<CKPlaySoundCinematicBloc>();

	kenv.addFactory<CAnimationDictionary>();
	kenv.addFactory<CKSoundDictionaryID>();

	kenv.addFactory<CKPFGraphTransition>();
	kenv.addFactory<CKBundle>();
	kenv.addFactory<CKSector>();
	kenv.addFactory<CKSpline4>();
	kenv.addFactory<CKChoreoKey>();
	kenv.addFactory<CKPFGraphNode>();
	kenv.addFactory<CKSas>();
	kenv.addFactory<CGround>();
	kenv.addFactory<CDynamicGround>();
	kenv.addFactory<CKFlaggedPath>();
	kenv.addFactory<CKMsgAction>();
	kenv.addFactory<CKChoreography>();
	kenv.addFactory<CKLine>();
	kenv.addFactory<CKSpline4L>();
	kenv.addFactory<CKCinematicScene>();
	kenv.addFactory<CKCinematicSceneData>();
	kenv.addFactory<CKMeshKluster>();
	kenv.addFactory<CKBeaconKluster>();
	kenv.addFactory<CKFlashNode2dFx>();
	kenv.addFactory<CKElectricArcNodeFx>();
	kenv.addFactory<CKQuadNodeFx>();
	kenv.addFactory<CKLightningObjectNodeFx>();
	kenv.addFactory<CKFilterNode2dFx>();
	kenv.addFactory<CKExplosionNodeFx>();
}

void ClassRegister::registerClassesForXXL2PlusPC(KEnvironment& kenv)
{
	// XXL2+ PC

	kenv.addFactory<CKServiceManager>();
	kenv.addFactory<CKGraphicX2>();
	kenv.addFactory<CKSoundManager>();
	kenv.addFactory<CKInput>();

	kenv.addFactory<CKServiceLife>();
	kenv.addFactory<CKSrvCollision>();
	kenv.addFactory<CKSrvCamera>();
	kenv.addFactory<CKSrvCinematic>();
	kenv.addFactory<CKSrvPathFinding>();
	kenv.addFactory<CKSrvAvoidance>();
	kenv.addFactory<CKSrvSekensor>();
	kenv.addFactory<CKSrvBeacon>();
	kenv.addFactory<CKSrvShadow>();
	kenv.addFactory<CKSrvProjectiles>();
	kenv.addFactory<CKSrvFx>();
	kenv.addFactory<CKSrvCounter>();
	kenv.addFactory<CKSrvTrigger>();
	kenv.addFactory<CKSrvDetect>();
	kenv.addFactory<CKSrvMusic>();

	kenv.addFactory<CKHkBasicBonus>();
	kenv.addFactory<CKHkCrate>();
	//---
	kenv.addFactory<GameX2::CKHkShoppingArea>();
	kenv.addFactory<GameX2::CKHkBonusSpitter>();
	kenv.addFactory<GameX2::CKHkPressionStone>();
	kenv.addFactory<GameX2::CKHkActivator>();
	kenv.addFactory<GameX2::CKHkDoor>();
	kenv.addFactory<GameX2::CKHkCrumblyZone>();
	//kenv.addFactory<GameX2::CKHkCrate>();
	//kenv.addFactory<GameX2::CKHkBasicBonus>();
	kenv.addFactory<GameX2::CKHkTelepher>();
	kenv.addFactory<GameX2::CKHkTelepherTowed>();
	kenv.addFactory<GameX2::CKHkA2JetPackEnemy>();
	kenv.addFactory<GameX2::CKHkMovableCharacter>();
	kenv.addFactory<GameX2::CKHkA2Hero>();
	kenv.addFactory<GameX2::CKHkLockMachineGun>();
	kenv.addFactory<GameX2::CKHkA2PotionStone>();
	kenv.addFactory<GameX2::CKHkA2Enemy>();
	kenv.addFactory<GameX2::CKHkCrumblyZoneAnimated>();
	kenv.addFactory<GameX2::CKHkDynamicObject>();
	kenv.addFactory<GameX2::CKHkPlatform>();
	kenv.addFactory<GameX2::CKHkWeatherCenter>();
	kenv.addFactory<GameX2::CKHkEnemyTarget>();
	kenv.addFactory<GameX2::CKHkEnemyTargetPit>();
	kenv.addFactory<GameX2::CKHkWaterWork>();
	kenv.addFactory<GameX2::CKHkSwitch>();
	kenv.addFactory<GameX2::CKHkCounter>();
	kenv.addFactory<GameX2::CKHkA2InvincibleEnemy>();
	kenv.addFactory<GameX2::CKHkCorridorEnemy>();
	kenv.addFactory<GameX2::CKHkTelepherAuto>();
	kenv.addFactory<GameX2::CKHkA2ArcherEnemy>();
	kenv.addFactory<GameX2::CKHkPushBomb>();
	kenv.addFactory<GameX2::CKHkMovableBloc>();
	kenv.addFactory<GameX2::CKHkParticlesSequencer>();
	kenv.addFactory<GameX2::CKHkA2TurtleEnemy>();
	kenv.addFactory<GameX2::CKHkCatapult>();
	kenv.addFactory<GameX2::CKHkA2Boss>();
	kenv.addFactory<GameX2::CKHkRollingBarrel>();
	kenv.addFactory<GameX2::CKHkFoldawayBridge>();
	kenv.addFactory<GameX2::CKHkBumper>();
	kenv.addFactory<GameX2::CKHkToll>();
	kenv.addFactory<GameX2::CKHkSlotMachine>();
	kenv.addFactory<GameX2::CKHkA2BossTrap>();
	kenv.addFactory<GameX2::CKHkCheckPoint>();
	kenv.addFactory<GameX2::CKHkA2CrumblyZone>();
	kenv.addFactory<GameX2::CKHkA2MarioEnemy>();
	kenv.addFactory<GameX2::CKHkA2DeathFx>();
	kenv.addFactory<GameX2::CKHkBonusHolder>();
	//---
	kenv.addFactory<GameOG::CKHkLightRay>();
	kenv.addFactory<GameOG::CKHkLightReceptacle>();
	kenv.addFactory<GameOG::CKHkFixedMirror>();
	kenv.addFactory<GameOG::CKHkOrientableMirror>();
	kenv.addFactory<GameOG::CKHkPushStack>();
	kenv.addFactory<GameOG::CKHkPressionStoneGroup>();
	//kenv.addFactory<GameOG::CKHkPressionStone>();
	kenv.addFactory<GameOG::CKCameraBeacon>();
	kenv.addFactory<GameOG::CKHkSavePoint>();
	kenv.addFactory<GameOG::CKHkA3Enemy>();
	kenv.addFactory<GameOG::CKHkBar>();
	kenv.addFactory<GameOG::CKHkPushObstacle>();
	kenv.addFactory<GameOG::CKHkPushStackType1>();
	kenv.addFactory<GameOG::CKHkPushStackType2>();
	kenv.addFactory<GameOG::CKHkButterflyBridge>();
	kenv.addFactory<GameOG::CKHkPushKillObject>();
	kenv.addFactory<GameOG::CKHkTrackerManager>();
	kenv.addFactory<GameOG::CKHkLinkedBeacon>();
	kenv.addFactory<GameOG::CKHkA3BurriedBonus>();
	kenv.addFactory<GameOG::CKHkScrapShower>();
	kenv.addFactory<GameOG::CKHkA3Compass>();
	kenv.addFactory<GameOG::CKHkLedge>();
	kenv.addFactory<GameOG::CKHkHeroBall>();
	kenv.addFactory<GameOG::CKHkHeroBallSpawner>();
	//kenv.addFactory<GameOG::CKHkDoor>();
	//kenv.addFactory<GameOG::CKHkCrumblyZone>();
	kenv.addFactory<GameOG::CKHkHeroActivator>();
	kenv.addFactory<GameOG::CKHkPxObject>();
	//kenv.addFactory<GameOG::CKHkBasicBonus>();
	kenv.addFactory<GameOG::CKHkA3Hero>();
	kenv.addFactory<GameOG::CKHkA3StepPlatformAirlock>();
	kenv.addFactory<GameOG::CKHkA3BirdZone>();
	kenv.addFactory<GameOG::CKHkA3Bird>();
	kenv.addFactory<GameOG::CKHkA3BirdCage>();
	kenv.addFactory<GameOG::CKHkEnemyTarget>();
	kenv.addFactory<GameOG::CKHkA3SoundActivator>();
	kenv.addFactory<GameOG::CKHkCounterWithDisplay>();
	kenv.addFactory<GameOG::CKHkA3PotionSpawner>();
	kenv.addFactory<GameOG::CKHkOlympicGameFrog>();
	kenv.addFactory<GameOG::CKHkFrogBall>();
	kenv.addFactory<GameOG::CKHkCrapombeBall>();
	kenv.addFactory<GameOG::CKHkBonusDistributor>();
	kenv.addFactory<GameOG::CKHkOlympicGameChar>();
	kenv.addFactory<GameOG::CKHkChar>();
	kenv.addFactory<GameOG::CKHkOlympicGameArena>();
	kenv.addFactory<GameOG::CKHkLaunchQuakeCamera>();
	kenv.addFactory<GameOG::CKHkOlympicGameJump>();
	kenv.addFactory<GameOG::CKHkMoss>();
	kenv.addFactory<GameOG::CKHkA3Moss>();
	kenv.addFactory<GameOG::CKHkOlympicGameJavelin>();
	kenv.addFactory<GameOG::CKHkOlympicGameRope>();
	kenv.addFactory<GameOG::CKHkOlympicGameHammer>();
	kenv.addFactory<GameOG::CKHkOlympicGameRace>();
	kenv.addFactory<GameOG::CKHkOlympicGameMusicalFight>();
	kenv.addFactory<GameOG::CKHkA3SeparationManager>();
	kenv.addFactory<GameOG::CKHkA3DDR>();
	kenv.addFactory<GameOG::CKHkA3PassManager>();
	//kenv.addFactory<GameOG::CKHkTelepher>();
	//kenv.addFactory<GameOG::CKHkTelepherTowed>();
	//kenv.addFactory<GameOG::CKHkMovableCharacter>();
	//kenv.addFactory<GameOG::CKHkCrumblyZoneAnimated>();
	//kenv.addFactory<GameOG::CKHkDynamicObject>();
	//kenv.addFactory<GameOG::CKHkPlatform>();
	//kenv.addFactory<GameOG::CKHkWeatherCenter>();
	//kenv.addFactory<GameOG::CKHkParticlesSequencer>();
	//kenv.addFactory<GameOG::CKHkRollingBarrel>();
	//kenv.addFactory<GameOG::CKHkFoldawayBridge>();


	kenv.addFactory<CKGroupRoot>();
	kenv.addFactory<CKGrpSquadX2>();
	kenv.addFactory<CKGrpPoolSquad>();
	kenv.addFactory<CKGrpBonusPool>();
	kenv.addFactory<CKGrpA2BonusPool>();
	kenv.addFactory<CKGrpBonusX2>();
	kenv.addFactory<CKGrpA3BonusPool>();
	//---
	kenv.addFactory<GameX2::CKGrpA2Boss>();
	kenv.addFactory<GameX2::CKGrpMeca>();
	//kenv.addFactory<GameX2::CKGrpSquad>();
	//kenv.addFactory<GameX2::CKGrpPoolSquad>();
	kenv.addFactory<GameX2::CKGrpCrate>();
	//kenv.addFactory<GameX2::CKGrpBonusPool>();
	kenv.addFactory<GameX2::CKGrpA2Hero>();
	kenv.addFactory<GameX2::CKGrpA2LevelPotion>();
	kenv.addFactory<GameX2::CKGrpLevelManager>();
	//kenv.addFactory<GameX2::CKGrpA2BonusPool>();
	//kenv.addFactory<GameX2::CKGrpBonus>();
	kenv.addFactory<GameX2::CKGrpA2Enemy>();
	kenv.addFactory<GameX2::CKGrpFightZone>();
	kenv.addFactory<GameX2::CKGrpMecaLast>();
	kenv.addFactory<GameX2::CKCommonBaseGroup>();
	kenv.addFactory<GameX2::CKFightZoneSectorGrpRoot>();
	kenv.addFactory<GameX2::CKGrpA2FoodBasket>();
	//---
	kenv.addFactory<GameOG::CKGrpStorage>();
	kenv.addFactory<GameOG::CKGrpPushStack>();
	kenv.addFactory<GameOG::CKGrpA3BurriedBonus>();
	//kenv.addFactory<GameOG::CKGrpSquad>();
	//kenv.addFactory<GameOG::CKGrpA3BonusPool>();
	kenv.addFactory<GameOG::CKGrpA3Hero>();
	kenv.addFactory<GameOG::CKGrpA3Meca>();
	kenv.addFactory<GameOG::CKGrpA3BirdCage>();
	kenv.addFactory<GameOG::CKGrpA3LevelPotion>();
	//kenv.addFactory<GameOG::CKGrpPoolSquad>();
	//kenv.addFactory<GameOG::CKGrpBonusPool>();
	//kenv.addFactory<GameOG::CKGrpLevelManager>();
	//kenv.addFactory<GameOG::CKGrpBonus>();
	//kenv.addFactory<GameOG::CKGrpA3Enemy>();
	//kenv.addFactory<GameOG::CKGrpFightZone>();
	//kenv.addFactory<GameOG::CKGrpMecaLast>();
	//kenv.addFactory<GameOG::CKCommonBaseGroup>();
	//kenv.addFactory<GameOG::CKFightZoneSectorGrpRoot>();

	kenv.addFactory<CKCrateCpnt>();
	//
	kenv.addFactory<GameX2::CKCorridorEnemyCpnt>();
	kenv.addFactory<GameX2::CKTargetCpnt>();
	kenv.addFactory<GameX2::CKCrumblyZoneCpnt>();
	kenv.addFactory<GameX2::CKCatapultCpnt>();
	kenv.addFactory<GameX2::CKShadowCpnt>();
	kenv.addFactory<GameX2::CKBonusCpnt>();
	kenv.addFactory<GameX2::CKA2EnemyCpnt>();
	kenv.addFactory<GameX2::CKA2JetPackEnemyCpnt>();
	kenv.addFactory<GameX2::CKWeatherPreset>();
	kenv.addFactory<GameX2::CKA2PotionStoneCpnt>();
	kenv.addFactory<GameX2::CKMecaCpnt>();
	kenv.addFactory<GameX2::CKBonusSpitterCpnt>();
	kenv.addFactory<GameX2::CKA2InvincibleEnemyCpnt>();
	kenv.addFactory<GameX2::CKA2ArcherEnemyCpnt>();
	kenv.addFactory<GameX2::CKPushBombCpnt>();
	kenv.addFactory<GameX2::CKPushCpnt>();
	kenv.addFactory<GameX2::CKParticlesSequencerCpnt>();
	kenv.addFactory<GameX2::CKMovableBlocCpnt>();
	kenv.addFactory<GameX2::CKRollingBarrelCpnt>();
	kenv.addFactory<GameX2::CKBumperCpnt>();
	kenv.addFactory<GameX2::CKA2ComboTwisterData>();
	kenv.addFactory<GameX2::CKA2ComboMenhirRainData>();
	kenv.addFactory<GameX2::CKSMCpnt>();
	kenv.addFactory<GameX2::CKA2ComboLightningData>();
	kenv.addFactory<GameX2::CKA2MarioEnemyCpnt>();
	kenv.addFactory<GameX2::CKTelepherTowedCpnt>();
	kenv.addFactory<GameX2::CKBonusHolderCpnt>();
	//
	kenv.addFactory<GameOG::CKEnemySectorCpnt>();

	kenv.addFactory<CKCamera>();
	kenv.addFactory<CKCameraRigidTrack>();
	//kenv.addFactory<CKCameraClassicTrack>();
	kenv.addFactory<CKCameraPathTrack>();
	kenv.addFactory<CKCameraFixTrack>();
	kenv.addFactory<CKCameraAxisTrack>();
	//kenv.addFactory<CKCameraSpyTrack>();
	kenv.addFactory<CKCameraPassivePathTrack>();
	kenv.addFactory<CKCameraBalistTrack>();
	kenv.addFactory<CKCameraClassicTrack2>();
	kenv.addFactory<CKCameraFirstPersonTrack>();

	kenv.addFactory<CKLogicalAnd>();
	kenv.addFactory<CKLogicalOr>();
	kenv.addFactory<CKPlayAnimCinematicBloc>();
	kenv.addFactory<CKPathFindingCinematicBloc>();
	kenv.addFactory<CKFlaggedPathCinematicBloc>();
	kenv.addFactory<CKGroupBlocCinematicBloc>();
	kenv.addFactory<CKAttachObjectsCinematicBloc>();
	kenv.addFactory<CKParticleCinematicBloc>();
	kenv.addFactory<CKStartDoor>();
	kenv.addFactory<CKSekensorCinematicBloc>();
	kenv.addFactory<CKDisplayPictureCinematicBloc>();
	kenv.addFactory<CKManageCameraCinematicBloc>();
	kenv.addFactory<CKStartEventCinematicBloc>();
	kenv.addFactory<CKLightningCinematicBloc>();
	kenv.addFactory<CKPlaySoundCinematicBloc>();
	kenv.addFactory<CKPauseCinematicBloc>();
	kenv.addFactory<CKTeleportCinematicBloc>();
	kenv.addFactory<CKEndDoor>();
	kenv.addFactory<CKPlayVideoCinematicBloc>();
	kenv.addFactory<CKFlashUICinematicBloc>();
	kenv.addFactory<CKLockUnlockCinematicBloc>();

	kenv.addFactory<CAnimationDictionary>();
	kenv.addFactory<CTextureDictionary>();
	kenv.addFactory<CKSoundDictionary>();
	kenv.addFactory<CKSoundDictionaryID>();

	kenv.addFactory<CKParticleGeometry>();
	kenv.addFactory<CKGeometry>();
	kenv.addFactory<CKSkinGeometry>();

	kenv.addFactory<CSGRootNode>();
	kenv.addFactory<CSGSectorRoot>();
	kenv.addFactory<CNode>();
	kenv.addFactory<CKDynBSphereProjectile>();
	kenv.addFactory<CSGLeaf>();
	kenv.addFactory<CSGBranch>();
	kenv.addFactory<CGlowNodeFx>();
	kenv.addFactory<CClone>();
	kenv.addFactory<CKBoundingSphere>();
	kenv.addFactory<CKDynamicBoundingSphere>();
	kenv.addFactory<CKAABB>();
	kenv.addFactory<CKOBB>();
	kenv.addFactory<CParticlesNodeFx>();
	kenv.addFactory<CAnimatedNode>();
	kenv.addFactory<CAnimatedClone>();
	kenv.addFactory<CKAACylinder>();
	kenv.addFactory<CSkyNodeFx>();
	kenv.addFactory<CFogBoxNodeFx>();
	kenv.addFactory<CTrailNodeFx>();
	kenv.addFactory<CSGLight>();
	kenv.addFactory<CCloudsNodeFx>();
	kenv.addFactory<CZoneNode>();
	kenv.addFactory<CSpawnNode>();
	kenv.addFactory<CSpawnAnimatedNode>();

	kenv.addFactory<CSGAnchor>();
	kenv.addFactory<CSGBkgRootNode>();

	kenv.addFactory<CKPFGraphTransition>();
	kenv.addFactory<CKBundle>();
	kenv.addFactory<CKSector>();
	kenv.addFactory<CKLevel>();
	kenv.addFactory<CKCameraSector>();
	kenv.addFactory<CKCoreManager>();
	kenv.addFactory<CKSpline4>();
	kenv.addFactory<CKChoreoKey>();
	kenv.addFactory<CKPFGraphNode>();
	kenv.addFactory<CKSas>();
	kenv.addFactory<CGround>();
	kenv.addFactory<CDynamicGround>();
	kenv.addFactory<CKFlaggedPath>();
	kenv.addFactory<CKChoreography>();
	kenv.addFactory<CKLine>();
	kenv.addFactory<CKSpline4L>();
	kenv.addFactory<CKCinematicScene>();
	kenv.addFactory<CLightComponent>();
	kenv.addFactory<CKCinematicSceneData>();
	kenv.addFactory<CKVibrationData>();
	kenv.addFactory<CLocManager>();
	kenv.addFactory<CKSekens>();
	kenv.addFactory<CKMeshKluster>();
	kenv.addFactory<CColorizedScreenData>();
	kenv.addFactory<CKBeaconKluster>();
	kenv.addFactory<CKProjectileTypeScrap>();
	kenv.addFactory<CKProjectileTypeBallisticPFX>();
	kenv.addFactory<CKTimeCounter>();
	kenv.addFactory<CKIntegerCounter>();
	kenv.addFactory<CKCombiner>();
	kenv.addFactory<CKComparator>();
	kenv.addFactory<CKComparedData>();
	kenv.addFactory<CKTrigger>();
	kenv.addFactory<CKProjectileTypeTargetLock>();
	kenv.addFactory<CKDetectorBase>();
	kenv.addFactory<CKSectorDetector>();
	kenv.addFactory<CMultiGeometry>();
	kenv.addFactory<CKDetectorEvent>();
	kenv.addFactory<CKDetectedMovable>();
	kenv.addFactory<CKTriggerDomain>();
	kenv.addFactory<CKSound>();
	kenv.addFactory<CSGHotSpot>();
	kenv.addFactory<CMaterial>();
	kenv.addFactory<CKFlashPlaySoundEvent>();
	kenv.addFactory<CKMusicPlayList>();
	kenv.addFactory<CKDetectorMusic>();
	kenv.addFactory<CMultiGeometryBasic>();
	kenv.addFactory<CKCameraQuakeDatas>();
	kenv.addFactory<CKA2GameState>();
	kenv.addFactory<CKCameraFogDatas>();
	kenv.addFactory<CKA3GameState>();
	kenv.addFactory<CKTriggerSynchro>();
	kenv.addFactory<CKStreamObject>();
	kenv.addFactory<CKStreamWave>();
	kenv.addFactory<CKDisplayBox>();
	kenv.addFactory<CKSekensBlock>();
	kenv.addFactory<CKSekensMarker>();
	// FxDatas
	kenv.addFactory<CKBlurFxData>();
	kenv.addFactory<CKHDRFxData>();
	kenv.addFactory<CKScreenColorFxData>();
	kenv.addFactory<CKFlashFxData>();
	kenv.addFactory<CKElectricArcFxData>();
	kenv.addFactory<CKExplosionFxData>();
	kenv.addFactory<CKShockWaveFxData>();
	kenv.addFactory<CKFireBallFxData>();
	kenv.addFactory<CKDistortionFxData>();
	kenv.addFactory<CKWaterWaveFxData>();
	kenv.addFactory<CKWaterSplashFxData>();
	kenv.addFactory<CKPowerBallFxData>();
	//
	kenv.addFactory<CKBlurNodeFx>();
	kenv.addFactory<CKHDRNodeFx>();
	kenv.addFactory<CKScreenColorNodeFx>();
	kenv.addFactory<CKFlashNode2dFx>();
	kenv.addFactory<CKElectricArcNodeFx>();
	kenv.addFactory<CKQuadNodeFx>();
	kenv.addFactory<CKLightningObjectNodeFx>();
	kenv.addFactory<CKFilterNode2dFx>();
	kenv.addFactory<CKExplosionNodeFx>();
	kenv.addFactory<CKHedgeHopTrailNodeFx>();
	kenv.addFactory<CKShockWaveNodeFx>();
	kenv.addFactory<CKFireBallNodeFx>();
	kenv.addFactory<CKDistortionNodeFx>();
	kenv.addFactory<CKWaterWaveNodeFx>();
	kenv.addFactory<CKWaterSplashNodeFx>();
	kenv.addFactory<CKPowerBallNodeFx>();
	//
	kenv.addFactory<GameX2::CKA2GameManager>();
	kenv.addFactory<GameX2::CKA2FlashInterface>();
	kenv.addFactory<GameX2::CKA2FlashInGameBoss>();
	kenv.addFactory<GameX2::CKA2FlashMenuOutGame>();
	kenv.addFactory<GameX2::CKA2FlashInGame>();
	kenv.addFactory<GameX2::CKA2FlashMenuInGame>();
	kenv.addFactory<GameX2::CKA2BossGrid>();
	kenv.addFactory<GameX2::CKA2BossCell>();
	kenv.addFactory<GameX2::CKA2BossSequence>();
	//
	kenv.addFactory<CKSandal>();
	kenv.addFactory<CKBomb>();
	kenv.addFactory<CKMarkerBeacon>();
	kenv.addFactory<CKExtendedMarkerBeacon>();
	kenv.addFactory<CKNumber>();
	//
	kenv.addFactory<GameX2::CKA2SpawnPoint>();
	kenv.addFactory<GameX2::CKA2GameStage>();
	kenv.addFactory<GameX2::CKA2GameModule>();
	kenv.addFactory<GameX2::CKA2DiamondHelmet>();
	kenv.addFactory<GameX2::CKA2Player>();
	kenv.addFactory<GameX2::CKA2ShoppingArea>();
	kenv.addFactory<GameX2::CKA2Video>();
	kenv.addFactory<GameX2::CKA2GameStructure>();

	kenv.addFactory<CCloneManager>();
	kenv.addFactory<CAnimationManager>();
	kenv.addFactory<CBillboard2d>();
	kenv.addFactory<CManager2d>();
	kenv.addFactory<CMenuManager>();
	kenv.addFactory<CContainer2d>();
	kenv.addFactory<CScene2d>();
	kenv.addFactory<CText2d>();
	kenv.addFactory<CSectorAnimation>();
	kenv.addFactory<CLightManager>();
	kenv.addFactory<CLightSet>();
	//
	kenv.addFactory<CBlurData>();
	kenv.addFactory<CKPBuffer>();
	kenv.addFactory<CPostRenderingFx>();
	kenv.addFactory<CHDRData>();
	kenv.addFactory<CKSpawnPoolParams>();
	kenv.addFactory<CBackgroundManager>();
	kenv.addFactory<CKFlashUI>();
	kenv.addFactory<CKFlashManager>();
	kenv.addFactory<CKFlashAnimation>();
	kenv.addFactory<CKFlashText>();
	kenv.addFactory<CKFlashMessageIn>();
	kenv.addFactory<CKFlashMessageOut>();
	kenv.addFactory<CVideoManager>();
	kenv.addFactory<WIN32_CKVideo>();
	kenv.addFactory<CSpawnManager>();
	kenv.addFactory<CKSpawnPool>();
	kenv.addFactory<CFlashHotSpot>();
	kenv.addFactory<CDistortionScreenFx>();
	kenv.addFactory<CDistortionScreenData>();
	kenv.addFactory<CColorizedScreenFx>();
	kenv.addFactory<CFlashMessageBox2d>();
}

void ClassRegister::registerClassesForXXL2PlusConsole(KEnvironment& kenv)
{
	// XXL2+ console

	kenv.addFactory<CKServiceManager>();
	kenv.addFactory<CKSoundManager>();

	kenv.addFactory<CKServiceLife>();
	kenv.addFactory<CKSrvCollision>();
	kenv.addFactory<CKSrvCinematic>();
	kenv.addFactory<CKSrvPathFinding>();
	kenv.addFactory<CKSrvAvoidance>();
	kenv.addFactory<CKSrvSekensor>();
	kenv.addFactory<CKSrvBeacon>();
	kenv.addFactory<CKSrvProjectiles>();
	kenv.addFactory<CKSrvCounter>();
	kenv.addFactory<CKSrvTrigger>();
	kenv.addFactory<CKSrvDetect>();
	kenv.addFactory<CKSrvMusic>();

	//kenv.addFactory<CKHkBasicBonus>();

	//kenv.addFactory<CKGrpSquadX2>();
	//kenv.addFactory<CKGrpPoolSquad>();
	//kenv.addFactory<CKGrpA2BonusPool>();

	//kenv.addFactory<CKCrateCpnt>();

	kenv.addFactory<CKLogicalAnd>();
	kenv.addFactory<CKLogicalOr>();
	kenv.addFactory<CKPlayAnimCinematicBloc>();
	kenv.addFactory<CKPathFindingCinematicBloc>();
	kenv.addFactory<CKFlaggedPathCinematicBloc>();
	kenv.addFactory<CKGroupBlocCinematicBloc>();
	kenv.addFactory<CKAttachObjectsCinematicBloc>();
	kenv.addFactory<CKParticleCinematicBloc>();
	kenv.addFactory<CKStartDoor>();
	kenv.addFactory<CKSekensorCinematicBloc>();
	kenv.addFactory<CKDisplayPictureCinematicBloc>();
	kenv.addFactory<CKManageCameraCinematicBloc>();
	kenv.addFactory<CKStartEventCinematicBloc>();
	kenv.addFactory<CKLightningCinematicBloc>();
	kenv.addFactory<CKPlaySoundCinematicBloc>();
	kenv.addFactory<CKPauseCinematicBloc>();
	kenv.addFactory<CKTeleportCinematicBloc>();
	kenv.addFactory<CKEndDoor>();
	kenv.addFactory<CKPlayVideoCinematicBloc>();
	kenv.addFactory<CKFlashUICinematicBloc>();
	kenv.addFactory<CKLockUnlockCinematicBloc>();

	kenv.addFactory<CAnimationDictionary>();
	kenv.addFactory<CTextureDictionary>();
	//kenv.addFactory<CKSoundDictionary>();
	kenv.addFactory<CKSoundDictionaryID>();

	kenv.addFactory<CKParticleGeometry>();
	kenv.addFactory<CKGeometry>();
	kenv.addFactory<CKSkinGeometry>();

	kenv.addFactory<CSGRootNode>();
	kenv.addFactory<CSGSectorRoot>();
	kenv.addFactory<CNode>();
	kenv.addFactory<CKDynBSphereProjectile>();
	kenv.addFactory<CSGLeaf>();
	kenv.addFactory<CSGBranch>();
	kenv.addFactory<CGlowNodeFx>();
	kenv.addFactory<CClone>();
	kenv.addFactory<CKBoundingSphere>();
	kenv.addFactory<CKDynamicBoundingSphere>();
	kenv.addFactory<CKAABB>();
	kenv.addFactory<CKOBB>();
	kenv.addFactory<CParticlesNodeFx>();
	kenv.addFactory<CAnimatedNode>();
	kenv.addFactory<CAnimatedClone>();
	kenv.addFactory<CKAACylinder>();
	kenv.addFactory<CSkyNodeFx>();
	kenv.addFactory<CFogBoxNodeFx>();
	kenv.addFactory<CTrailNodeFx>();
	kenv.addFactory<CSGLight>();
	kenv.addFactory<CCloudsNodeFx>();
	kenv.addFactory<CZoneNode>();
	kenv.addFactory<CSpawnNode>();
	kenv.addFactory<CSpawnAnimatedNode>();
	//
	kenv.addFactory<CSGAnchor>();
	kenv.addFactory<CSGBkgRootNode>();
	//
	kenv.addFactory<CKPartlyUnknown<CNode, 28>>(); // Spark emitter
	kenv.addFactory<CKPartlyUnknown<CKSceneNode, 37>>(); // Point Light (Spyro360)

	kenv.addFactory<CKPFGraphTransition>();
	kenv.addFactory<CKBundle>();
	kenv.addFactory<CKSector>();
	kenv.addFactory<CKLevel>();
	kenv.addFactory<CKCameraSector>();
	kenv.addFactory<CKCoreManager>();
	kenv.addFactory<CKSpline4>();
	kenv.addFactory<CKChoreoKey>();
	kenv.addFactory<CKPFGraphNode>();
	kenv.addFactory<CKSas>();
	kenv.addFactory<CGround>();
	kenv.addFactory<CDynamicGround>();
	kenv.addFactory<CKFlaggedPath>();
	kenv.addFactory<CKChoreography>();
	kenv.addFactory<CKLine>();
	kenv.addFactory<CKSpline4L>();
	kenv.addFactory<CKCinematicScene>();
	kenv.addFactory<CKCinematicSceneData>();
	kenv.addFactory<CLocManager>();
	kenv.addFactory<CKMeshKluster>();
	kenv.addFactory<CKBeaconKluster>();
	kenv.addFactory<CKTimeCounter>();
	kenv.addFactory<CKIntegerCounter>();
	kenv.addFactory<CKCombiner>();
	kenv.addFactory<CKComparator>();
	kenv.addFactory<CKComparedData>();
	kenv.addFactory<CKTrigger>();
	kenv.addFactory<CKDetectorBase>();
	kenv.addFactory<CKSectorDetector>();
	kenv.addFactory<CMultiGeometry>();
	kenv.addFactory<CKDetectorEvent>();
	kenv.addFactory<CKDetectedMovable>();
	kenv.addFactory<CKTriggerDomain>();
	kenv.addFactory<CSGHotSpot>();
	//kenv.addFactory<CMaterial>();
	kenv.addFactory<CKMusicPlayList>();
	kenv.addFactory<CKDetectorMusic>();
	kenv.addFactory<CMultiGeometryBasic>();
	kenv.addFactory<CKA2GameState>();
	kenv.addFactory<CKA3GameState>();
	kenv.addFactory<CKTriggerSynchro>();
	kenv.addFactory<CKStreamObject>();
	kenv.addFactory<CKStreamWave>();
	kenv.addFactory<CKDisplayBox>();
	kenv.addFactory<CKSekensBlock>();
	kenv.addFactory<CKSekensMarker>();
	//
	kenv.addFactory<CKArGameState>();
	kenv.addFactory<CKS08GameState>();

	kenv.addFactory<CCloneManager>();
	//kenv.addFactory<CAnimationManager>();
	kenv.addFactory<CBillboard2d>();
	kenv.addFactory<CManager2d>();
	//kenv.addFactory<CSectorAnimation>();
	kenv.addFactory<CLightManager>();
	kenv.addFactory<CLightSet>();
}

static void registerClassesForArthur(KEnvironment& kenv)
{
	kenv.addFactory<CKServiceManager>();
	kenv.addFactory<CKSoundManager>();

	kenv.addFactory<CKServiceLife>();
	kenv.addFactory<CKSrvCollision>();
	kenv.addFactory<CKSrvCamera>();
	kenv.addFactory<CKSrvCinematic>();
	kenv.addFactory<CKSrvPathFinding>();
	kenv.addFactory<CKSrvAvoidance>();
	kenv.addFactory<CKSrvSekensor>();
	kenv.addFactory<CKSrvBeacon>();
	kenv.addFactory<CKSrvShadow>();
	kenv.addFactory<CKSrvProjectiles>();
	kenv.addFactory<CKSrvFx>();
	kenv.addFactory<CKSrvCounter>();
	kenv.addFactory<CKSrvTrigger>();
	kenv.addFactory<CKSrvDetect>();
	kenv.addFactory<CKSrvMusic>();

	kenv.addFactory<CKHkBasicBonus>();
	kenv.addFactory<CKHkCrate>();
	//---
	kenv.addFactory<GameX2::CKHkShoppingArea>();
	kenv.addFactory<GameX2::CKHkBonusSpitter>();
	kenv.addFactory<GameX2::CKHkPressionStone>();
	kenv.addFactory<GameX2::CKHkActivator>();
	kenv.addFactory<GameX2::CKHkDoor>();
	kenv.addFactory<GameX2::CKHkCrumblyZone>();
	//kenv.addFactory<GameX2::CKHkCrate>();
	//kenv.addFactory<GameX2::CKHkBasicBonus>();
	kenv.addFactory<GameX2::CKHkTelepher>();
	kenv.addFactory<GameX2::CKHkTelepherTowed>();
	kenv.addFactory<GameX2::CKHkA2JetPackEnemy>();
	kenv.addFactory<GameX2::CKHkMovableCharacter>();
	kenv.addFactory<GameX2::CKHkA2Hero>();
	kenv.addFactory<GameX2::CKHkLockMachineGun>();
	kenv.addFactory<GameX2::CKHkA2PotionStone>();
	kenv.addFactory<GameX2::CKHkA2Enemy>();
	kenv.addFactory<GameX2::CKHkCrumblyZoneAnimated>();
	kenv.addFactory<GameX2::CKHkDynamicObject>();
	kenv.addFactory<GameX2::CKHkPlatform>();
	kenv.addFactory<GameX2::CKHkWeatherCenter>();
	kenv.addFactory<GameX2::CKHkEnemyTarget>();
	kenv.addFactory<GameX2::CKHkEnemyTargetPit>();
	kenv.addFactory<GameX2::CKHkWaterWork>();
	kenv.addFactory<GameX2::CKHkSwitch>();
	kenv.addFactory<GameX2::CKHkCounter>();
	kenv.addFactory<GameX2::CKHkA2InvincibleEnemy>();
	kenv.addFactory<GameX2::CKHkCorridorEnemy>();
	kenv.addFactory<GameX2::CKHkTelepherAuto>();
	kenv.addFactory<GameX2::CKHkA2ArcherEnemy>();
	kenv.addFactory<GameX2::CKHkPushBomb>();
	kenv.addFactory<GameX2::CKHkMovableBloc>();
	kenv.addFactory<GameX2::CKHkParticlesSequencer>();
	kenv.addFactory<GameX2::CKHkA2TurtleEnemy>();
	kenv.addFactory<GameX2::CKHkCatapult>();
	kenv.addFactory<GameX2::CKHkA2Boss>();
	kenv.addFactory<GameX2::CKHkRollingBarrel>();
	kenv.addFactory<GameX2::CKHkFoldawayBridge>();
	kenv.addFactory<GameX2::CKHkBumper>();
	kenv.addFactory<GameX2::CKHkToll>();
	kenv.addFactory<GameX2::CKHkSlotMachine>();
	kenv.addFactory<GameX2::CKHkA2BossTrap>();
	kenv.addFactory<GameX2::CKHkCheckPoint>();
	kenv.addFactory<GameX2::CKHkA2CrumblyZone>();
	kenv.addFactory<GameX2::CKHkA2MarioEnemy>();
	kenv.addFactory<GameX2::CKHkA2DeathFx>();
	kenv.addFactory<GameX2::CKHkBonusHolder>();
	//---
	kenv.addFactory<GameOG::CKHkLightRay>();
	kenv.addFactory<GameOG::CKHkLightReceptacle>();
	kenv.addFactory<GameOG::CKHkFixedMirror>();
	kenv.addFactory<GameOG::CKHkOrientableMirror>();
	kenv.addFactory<GameOG::CKHkPushStack>();
	kenv.addFactory<GameOG::CKHkPressionStoneGroup>();
	//kenv.addFactory<GameOG::CKHkPressionStone>();
	kenv.addFactory<GameOG::CKCameraBeacon>();
	kenv.addFactory<GameOG::CKHkSavePoint>();
	//kenv.addFactory<GameOG::CKHkA3Enemy>();
	kenv.addFactory<GameOG::CKHkBar>();
	kenv.addFactory<GameOG::CKHkPushObstacle>();
	kenv.addFactory<GameOG::CKHkPushStackType1>();
	kenv.addFactory<GameOG::CKHkPushStackType2>();
	kenv.addFactory<GameOG::CKHkButterflyBridge>();
	kenv.addFactory<GameOG::CKHkPushKillObject>();
	kenv.addFactory<GameOG::CKHkTrackerManager>();
	kenv.addFactory<GameOG::CKHkLinkedBeacon>();
	kenv.addFactory<GameOG::CKHkA3BurriedBonus>();
	kenv.addFactory<GameOG::CKHkScrapShower>();
	kenv.addFactory<GameOG::CKHkA3Compass>();
	kenv.addFactory<GameOG::CKHkLedge>();
	kenv.addFactory<GameOG::CKHkHeroBall>();
	kenv.addFactory<GameOG::CKHkHeroBallSpawner>();
	//kenv.addFactory<GameOG::CKHkDoor>();
	//kenv.addFactory<GameOG::CKHkCrumblyZone>();
	kenv.addFactory<GameOG::CKHkHeroActivator>();
	kenv.addFactory<GameOG::CKHkPxObject>();
	//kenv.addFactory<GameOG::CKHkBasicBonus>();
	kenv.addFactory<GameOG::CKHkA3Hero>();
	kenv.addFactory<GameOG::CKHkA3StepPlatformAirlock>();
	kenv.addFactory<GameOG::CKHkA3BirdZone>();
	kenv.addFactory<GameOG::CKHkA3Bird>();
	kenv.addFactory<GameOG::CKHkA3BirdCage>();
	kenv.addFactory<GameOG::CKHkEnemyTarget>();
	kenv.addFactory<GameOG::CKHkA3SoundActivator>();
	kenv.addFactory<GameOG::CKHkCounterWithDisplay>();
	kenv.addFactory<GameOG::CKHkA3PotionSpawner>();
	kenv.addFactory<GameOG::CKHkOlympicGameFrog>();
	kenv.addFactory<GameOG::CKHkFrogBall>();
	kenv.addFactory<GameOG::CKHkCrapombeBall>();
	kenv.addFactory<GameOG::CKHkLaunchQuakeCamera>();

	//kenv.addFactory<CKGroupRoot>();
	kenv.addFactory<CKGrpSquadX2>();
	kenv.addFactory<CKGrpPoolSquad>();
	kenv.addFactory<CKGrpBonusPool>();
	kenv.addFactory<CKGrpA2BonusPool>();
	kenv.addFactory<CKGrpBonusX2>();
	kenv.addFactory<CKGrpA3BonusPool>();
	kenv.addFactory<CKGrpArBonusPool>();
	kenv.addFactory<GameX2::CKGrpMeca>();
	kenv.addFactory<GameX2::CKGrpCrate>();
	kenv.addFactory<GameX2::CKGrpLevelManager>();
	kenv.addFactory<GameX2::CKGrpFightZone>();
	kenv.addFactory<GameX2::CKGrpMecaLast>();
	kenv.addFactory<GameX2::CKCommonBaseGroup>();
	kenv.addFactory<GameX2::CKFightZoneSectorGrpRoot>();
	kenv.addFactory<GameX2::CKGrpA2FoodBasket>();
	kenv.addFactory<GameOG::CKGrpStorage>();
	kenv.addFactory<GameOG::CKGrpPushStack>();
	kenv.addFactory<GameOG::CKGrpA3BurriedBonus>();
	kenv.addFactory<GameOG::CKGrpA3Hero>();
	kenv.addFactory<GameOG::CKGrpA3Meca>();
	kenv.addFactory<GameOG::CKGrpA3BirdCage>();
	kenv.addFactory<GameOG::CKGrpA3LevelPotion>();

	kenv.addFactory<CKCrateCpnt>();
	//
	kenv.addFactory<GameX2::CKCorridorEnemyCpnt>();
	kenv.addFactory<GameX2::CKTargetCpnt>();
	kenv.addFactory<GameX2::CKCrumblyZoneCpnt>();
	kenv.addFactory<GameX2::CKCatapultCpnt>();
	kenv.addFactory<GameX2::CKShadowCpnt>();
	kenv.addFactory<GameX2::CKBonusCpnt>();
	kenv.addFactory<GameX2::CKWeatherPreset>();
	kenv.addFactory<GameX2::CKMecaCpnt>();
	kenv.addFactory<GameX2::CKBonusSpitterCpnt>();
	kenv.addFactory<GameX2::CKPushBombCpnt>();
	kenv.addFactory<GameX2::CKPushCpnt>();
	kenv.addFactory<GameX2::CKMovableBlocCpnt>();
	kenv.addFactory<GameX2::CKRollingBarrelCpnt>();
	kenv.addFactory<GameX2::CKBumperCpnt>();
	kenv.addFactory<GameX2::CKBonusHolderCpnt>();
	//
	//kenv.addFactory<GameOG::CKEnemySectorCpnt>();

	kenv.addFactory<CKCamera>();
	kenv.addFactory<CKCameraRigidTrack>();
	//kenv.addFactory<CKCameraClassicTrack>();
	kenv.addFactory<CKCameraPathTrack>();
	kenv.addFactory<CKCameraFixTrack>();
	kenv.addFactory<CKCameraAxisTrack>();
	kenv.addFactory<CKCameraSpyTrack>();
	kenv.addFactory<CKCameraPassivePathTrack>();
	kenv.addFactory<CKCameraBalistTrack>();
	kenv.addFactory<CKCameraClassicTrack2>();
	kenv.addFactory<CKCameraFirstPersonTrack>();

	kenv.addFactory<CKLogicalAnd>();
	kenv.addFactory<CKLogicalOr>();
	kenv.addFactory<CKPlayAnimCinematicBloc>();
	kenv.addFactory<CKPathFindingCinematicBloc>();
	kenv.addFactory<CKFlaggedPathCinematicBloc>();
	kenv.addFactory<CKGroupBlocCinematicBloc>();
	kenv.addFactory<CKAttachObjectsCinematicBloc>();
	kenv.addFactory<CKParticleCinematicBloc>();
	kenv.addFactory<CKStartDoor>();
	kenv.addFactory<CKSekensorCinematicBloc>();
	kenv.addFactory<CKDisplayPictureCinematicBloc>();
	kenv.addFactory<CKManageCameraCinematicBloc>();
	kenv.addFactory<CKStartEventCinematicBloc>();
	kenv.addFactory<CKLightningCinematicBloc>();
	kenv.addFactory<CKPlaySoundCinematicBloc>();
	kenv.addFactory<CKPauseCinematicBloc>();
	kenv.addFactory<CKTeleportCinematicBloc>();
	kenv.addFactory<CKEndDoor>();
	kenv.addFactory<CKPlayVideoCinematicBloc>();
	kenv.addFactory<CKFlashUICinematicBloc>();
	kenv.addFactory<CKLockUnlockCinematicBloc>();

	kenv.addFactory<CAnimationDictionary>();
	kenv.addFactory<CTextureDictionary>();
	//kenv.addFactory<CKSoundDictionary>();
	kenv.addFactory<CKSoundDictionaryID>();

	kenv.addFactory<CKParticleGeometry>();
	kenv.addFactory<CKGeometry>();
	kenv.addFactory<CKSkinGeometry>();

	kenv.addFactory<CSGRootNode>();
	kenv.addFactory<CSGSectorRoot>();
	kenv.addFactory<CNode>();
	kenv.addFactory<CKDynBSphereProjectile>();
	kenv.addFactory<CSGLeaf>();
	kenv.addFactory<CSGBranch>();
	kenv.addFactory<CGlowNodeFx>();
	kenv.addFactory<CClone>();
	kenv.addFactory<CKBoundingSphere>();
	kenv.addFactory<CKDynamicBoundingSphere>();
	kenv.addFactory<CKAABB>();
	kenv.addFactory<CKOBB>();
	kenv.addFactory<CParticlesNodeFx>();
	kenv.addFactory<CAnimatedNode>();
	kenv.addFactory<CAnimatedClone>();
	kenv.addFactory<CKAACylinder>();
	kenv.addFactory<CSkyNodeFx>();
	kenv.addFactory<CFogBoxNodeFx>();
	kenv.addFactory<CTrailNodeFx>();
	kenv.addFactory<CSGLight>();
	kenv.addFactory<CCloudsNodeFx>();
	kenv.addFactory<CZoneNode>();
	kenv.addFactory<CSpawnNode>();
	kenv.addFactory<CSpawnAnimatedNode>();

	kenv.addFactory<CSGAnchor>();
	kenv.addFactory<CSGBkgRootNode>();

	kenv.addFactory<CKPFGraphTransition>();
	kenv.addFactory<CKBundle>();
	kenv.addFactory<CKSector>();
	kenv.addFactory<CKLevel>();
	kenv.addFactory<CKCameraSector>();
	kenv.addFactory<CKCoreManager>();
	kenv.addFactory<CKSpline4>();
	kenv.addFactory<CKChoreoKey>();
	kenv.addFactory<CKPFGraphNode>();
	kenv.addFactory<CKSas>();
	kenv.addFactory<CGround>();
	kenv.addFactory<CDynamicGround>();
	kenv.addFactory<CKFlaggedPath>();
	kenv.addFactory<CKChoreography>();
	kenv.addFactory<CKLine>();
	kenv.addFactory<CKSpline4L>();
	kenv.addFactory<CKCinematicScene>();
	kenv.addFactory<CLightComponent>();
	kenv.addFactory<CKCinematicSceneData>();
	kenv.addFactory<CKVibrationData>();
	kenv.addFactory<CLocManager>();
	kenv.addFactory<CKSekens>();
	kenv.addFactory<CKMeshKluster>();
	kenv.addFactory<CColorizedScreenData>();
	kenv.addFactory<CKBeaconKluster>();
	kenv.addFactory<CKProjectileTypeScrap>();
	//kenv.addFactory<CKProjectileTypeBallisticPFX>();
	kenv.addFactory<CKTimeCounter>();
	kenv.addFactory<CKIntegerCounter>();
	kenv.addFactory<CKCombiner>();
	kenv.addFactory<CKComparator>();
	kenv.addFactory<CKComparedData>();
	kenv.addFactory<CKTrigger>();
	//kenv.addFactory<CKProjectileTypeTargetLock>();
	kenv.addFactory<CKDetectorBase>();
	kenv.addFactory<CKSectorDetector>();
	kenv.addFactory<CMultiGeometry>();
	kenv.addFactory<CKDetectorEvent>();
	kenv.addFactory<CKDetectedMovable>();
	kenv.addFactory<CKTriggerDomain>();
	kenv.addFactory<CKSound>();
	kenv.addFactory<CSGHotSpot>();
	kenv.addFactory<CMaterial>();
	//kenv.addFactory<CKFlashPlaySoundEvent>();
	kenv.addFactory<CKMusicPlayList>();
	kenv.addFactory<CKDetectorMusic>();
	kenv.addFactory<CMultiGeometryBasic>();
	//kenv.addFactory<CKCameraQuakeDatas>();
	//kenv.addFactory<CKCameraFogDatas>();
	kenv.addFactory<CKTriggerSynchro>();
	kenv.addFactory<CKStreamObject>();
	kenv.addFactory<CKStreamWave>();
	kenv.addFactory<CKDisplayBox>();
	kenv.addFactory<CKSekensBlock>();
	kenv.addFactory<CKSekensMarker>();
	
	kenv.addFactory<CKArGameState>();

	kenv.addFactory<CCloneManager>();
	kenv.addFactory<CAnimationManager>();
	kenv.addFactory<CBillboard2d>();
	kenv.addFactory<CManager2d>();
	kenv.addFactory<CMenuManager>();
	kenv.addFactory<CContainer2d>();
	kenv.addFactory<CScene2d>();
	kenv.addFactory<CText2d>();
	kenv.addFactory<CSectorAnimation>();
	kenv.addFactory<CLightManager>();
	kenv.addFactory<CLightSet>();
}

static void registerClassesForAlice(KEnvironment& kenv)
{
	// Service Managers - Done
	kenv.addFactory<CKServiceManager>(); // (0, 1)
	// kenv.addFactory<CKGraphic>(); // (0, 2)
	kenv.addFactory<CKSoundManager>(); // (0, 3)
	kenv.addFactory<CKInput>(); // (0, 4)
	// kenv.addFactory<CKSoundOutputEffect>(); // (0, 5)


	// Services - Done
	kenv.addFactory<CKServiceLife>(); // (1, 1)
	kenv.addFactory<CKSrvCollision>(); // (1, 2)
	// kenv.addFactory<CKSrvCamera>(); // (1, 3)
	kenv.addFactory<CKSrvCinematic>(); // (1, 4)
	kenv.addFactory<CKSrvPathFinding>(); // (1, 6)
	// kenv.addFactory<CKSrvBonus>(); // (1, 7)
	kenv.addFactory<CKSrvAvoidance>(); // (1, 9)
	kenv.addFactory<CKSrvSekensor>(); // (1, 10)
	kenv.addFactory<CKSrvBeacon>(); // (1, 11)
	// kenv.addFactory<CKSrvShadow>(); // (1, 12)
	kenv.addFactory<CKSrvProjectiles>(); // (1, 13)
	// kenv.addFactory<CKSrvFx>(); // (1, 14)
	// kenv.addFactory<CKSrvPhysics>(); // (1, 15)
	kenv.addFactory<CKSrvCounter>(); // (1, 17)
	kenv.addFactory<CKSrvTrigger>(); // (1, 18)
	kenv.addFactory<CKSrvDetect>(); // (1, 19)
	kenv.addFactory<CKSrvMusic>(); // (1, 20)
	if (kenv.platform == kenv.PLATFORM_PC)
	{
		// kenv.addFactory<CKSrvNetwork>(); // (1, 24)
	}
	else if (kenv.platform == kenv.PLATFORM_WII)
	{
		// kenv.addFactory<Revolution_CKSrvNetwork>(); // (1, 24)
	}
	// kenv.addFactory<CKSrvInput>(); // (1, 27)
	// kenv.addFactory<CKSrvDynamic>(); // (1, 28)
	// kenv.addFactory<CKSrvInputCommands>(); // (1, 29)


	// Hooks - Done
	// kenv.addFactory<CKCameraBeacon>(); // (2, 22)
	// kenv.addFactory<CKHkLinkedBeacon>(); // (2, 64)
	// kenv.addFactory<CKHkDoor>(); // (2, 101)
	// kenv.addFactory<CKHkHeroActivator>(); // (2, 104)
	// kenv.addFactory<CKHkLaunchQuakeCamera>(); // (2, 136)
	// kenv.addFactory<CKHkAliceHero>(); // (2, 151)
	// kenv.addFactory<CKHkDetectorGroup>(); // (2, 182)
	// kenv.addFactory<CKHkAliceSavePoint>(); // (2, 184)
	// kenv.addFactory<CKHkMovingObject>(); // (2, 201)
	// kenv.addFactory<CKHkScriptedNPC>(); // (2, 203)
	// kenv.addFactory<CKHkAliceBonus>(); // (2, 204)
	// kenv.addFactory<CKHkMovableCharacter>(); // (2, 208)
	// kenv.addFactory<CKHkMecaSound>(); // (2, 210)
	// kenv.addFactory<CKHkAliceCrumblyZoneMultiState>(); // 2 IDs?? (2, 211), (2, 242) ????
	// kenv.addFactory<CKHkAliceDoor>(); // (2, 264)
	// kenv.addFactory<CKHkAliceEnemy>(); // (2, 274)
	// kenv.addFactory<CKHkAliceSpCrumblyZone>(); // (2, 277)
	// kenv.addFactory<CKHkSplineMeca>(); // (2, 283)
	// kenv.addFactory<CKHkAliceTelekinesisNode>(); // (2, 284)
	// kenv.addFactory<CKHkAliceTelekinesisMeca>(); // (2, 286)
	// kenv.addFactory<CKHkContextualMove>(); // (2, 293)
	// kenv.addFactory<CKHkAliceBanderSnatch>(); // (2, 294)
	// kenv.addFactory<CKHkAnimSequenceMgr>(); // (2, 300)
	// kenv.addFactory<CKHkAliceMovableCharacter>(); // (2, 303)
	// kenv.addFactory<CKHkAliceEnemyStayne>(); // (2, 304)
	// kenv.addFactory<CKHkAliceShopPoint>(); // (2, 306)
	// kenv.addFactory<CKHkAliceJabberwocky>(); // (2, 308)
	// kenv.addFactory<CKHkAliceEdgeUpdater>(); // (2, 309)


	// Groups - Done
	// kenv.addFactory<CKGroupRoot>(); // (4, 1)
	// kenv.addFactory<CKGrpStorage>(); // (4, 8)
	// kenv.addFactory<CKGrpMeca>(); // (4, 11)
	// kenv.addFactory<CKGrpSquad>(); // (4, 24)
	// kenv.addFactory<CKGrpAliceBonusPool>(); // (4, 31)
	// kenv.addFactory<CKGrpAliceHero>(); // (4, 55)
	// kenv.addFactory<CKGrpAliceEnemy>(); // (4, 57)
	// kenv.addFactory<CKGrpAlicePoolEnemy>(); // (4, 58)
	// kenv.addFactory<CKGrpAliceSpCrumblyZone>(); // (4, 59)
	// kenv.addFactory<CKGrpLevelManager>(); // (4, 89)
	// kenv.addFactory<CKGrpBonus>(); // (4, 92)
	// kenv.addFactory<CKGrpFightZone>(); // (4, 95)
	// kenv.addFactory<CKCommonBaseGroup>(); // (4, 99)
	// kenv.addFactory<CKFightZoneSectorGrpRoot>(); // (4, 100)
	

	// Components - Done
	// kenv.addFactory<CKEnemySectorCpnt>(); // (6, 14)
	// kenv.addFactory<CKPathStepCpnt>(); // (6, 17)
	kenv.addFactory<CKShadowCpnt>(); // (6, 18)
	// kenv.addFactory<CKParticlesCpnt>(); // (6, 25)
	// kenv.addFactory<CKBonusData>(); // (6, 26)
	// kenv.addFactory<CKImpulsionCpnt>(); // (6, 32)
	// kenv.addFactory<CKSinCurve2DCpnt>(); // (6, 34)
	// kenv.addFactory<CKQuakeCpntUpdater>(); // (6, 38)
	// kenv.addFactory<CKQuakeCameraLauncher>(); // (6, 42)
	// kenv.addFactory<CKSekensLauncherCpnt>(); // (6, 53)
	// kenv.addFactory<CKLocTextAccessor>(); // (6, 57)
	// kenv.addFactory<CKGroundCpnt>(); // (6, 72)
	// kenv.addFactory<CKMoveCpntUpdater>(); // (6, 75)
	// kenv.addFactory<CKAliceBonusCpnt>(); // (6, 76)
	// kenv.addFactory<CKBoundingCpnt>(); // (6, 78)
	// kenv.addFactory<CKCinematicStreamCpnt>(); // (6, 79)
	// kenv.addFactory<CKTransformationCpntUpdater>(); // (6, 81)
	// kenv.addFactory<CKGaugeCpntUpdater>(); // (6, 82)
	// kenv.addFactory<CKAttachCpnt>(); // (6, 86)
	// kenv.addFactory<CKAttachCpntUpdater>(); // (6, 87)
	// kenv.addFactory<CKRessourceCpnt>(); // (6, 99)
	// kenv.addFactory<CKHeroAbilityConfigWalk>(); // (6, 104)
	// kenv.addFactory<CKHeroAbilityConfigRun>(); // (6, 105)
	// kenv.addFactory<CKHeroAbilityConfigJump>(); // (6, 106)
	// kenv.addFactory<CKHeroAbilityConfigDoubleJump>(); // (6, 107) - This game doesn't have a double jump??
	// kenv.addFactory<CKPickableCpntManager>(); // (6, 115)
	// kenv.addFactory<CKPickableCpnt>(); // (6, 116)
	// kenv.addFactory<CKAliceHeroConfig>(); // (6, 117)
	// kenv.addFactory<CKHeroAbilityConfigSlap>(); // (6, 121)
	// kenv.addFactory<CKAlicePowerLauncher>(); // (6, 122)
	// kenv.addFactory<CKAliceFightZoneCpnt>(); // (6, 123)
	// kenv.addFactory<CKAliceEnemyCpnt>(); // (6, 124)
	// kenv.addFactory<CKAliceAccessoryConfig>(); // (6, 125)
	// kenv.addFactory<CKAliceAccessoryManager>(); // (6, 126)
	// kenv.addFactory<CKAliceAccessory>(); // (6, 127)
	// kenv.addFactory<CKAliceAccessoryPool>(); // (6, 128)
	// kenv.addFactory<CKHeroAbilityConfigCombo>(); // (6, 129)
	// kenv.addFactory<CKAliceAccessoryData>(); // (6, 131)
	// kenv.addFactory<CKAliceHeroConfigAlice>(); // (6, 132)
	// kenv.addFactory<CKHeroAbilityConfigStatic>(); // (6, 134)
	// kenv.addFactory<CKHeroAbilityConfigRandomScream>(); // (6, 135)
	// kenv.addFactory<CKHeroAbilityConfigTargetLock>(); // (6, 136)
	// kenv.addFactory<CKHeroAbilityConfigPlunge>(); // (6, 137)
	// kenv.addFactory<CKHeroAbilityConfigAlternativeRun>(); // (6, 139)
	// kenv.addFactory<CKHeroAbilityConfigAlternativeWalk>(); // (6, 140)
	// kenv.addFactory<CKAliceHeroAbilityConfigParry>(); // (6, 141)
	// kenv.addFactory<CKAliceHeroAbilityConfigBackStab>(); // (6, 142)
	// kenv.addFactory<CKAliceHeroAbilityConfigCoupDeGrace>(); // (6, 149)
	// kenv.addFactory<CKAliceHeroAbilityConfigOffensiveDodge>(); // (6, 154)
	// kenv.addFactory<CKCurve2DCpnt>(); // (6, 363)
	// kenv.addFactory<CKAliceHeroAbilityConfigThrowOff>(); // (6, 998)


	// Camera - Done
	// kenv.addFactory<CKCamera>();// (7, 1)
	// kenv.addFactory<CKCameraPathTrack>(); // (7, 4)
	// kenv.addFactory<CKCameraFixTrack>(); // (7, 6)
	// kenv.addFactory<CKCameraPassivePathTrack>(); // (7, 10)
	// kenv.addFactory<CKCameraClassicTrack3>(); // (7, 14)
	// kenv.addFactory<CKCameraFly>(); // (7, 16)


	// Cinematic Blocks - Done
	kenv.addFactory<CKLogicalAnd>(); // (8, 1)
	kenv.addFactory<CKLogicalOr>(); // (8, 2)
	// kenv.addFactory<CKPlayAnimCinematicBloc>(); // (8, 3)
	kenv.addFactory<CKPathFindingCinematicBloc>(); // (8, 4)
	// kenv.addFactory<CKFlaggedPathCinematicBloc>(); // (8, 5)
	kenv.addFactory<CKGroupBlocCinematicBloc>(); // (8, 7)
	// kenv.addFactory<CKAdvancedCameraCinematicBloc>(); // (8, 8)
	// kenv.addFactory<CKStreamAnimCinematicBloc>(); // (8, 10)
	// kenv.addFactory<CKCharacterControlBloc>(); // (8, 13)
	// kenv.addFactory<CKStreamAnimCinematicBeginBloc>(); // (8, 14)
	// kenv.addFactory<CKStreamAnimCinematicEndBloc>(); // (8, 15)
	kenv.addFactory<CKStartDoor>(); // (8, 17)
	kenv.addFactory<CKSekensorCinematicBloc>(); // (8, 20)
	kenv.addFactory<CKDisplayPictureCinematicBloc>(); // (8, 22)
	kenv.addFactory<CKManageCameraCinematicBloc>(); // (8, 23)
	kenv.addFactory<CKStartEventCinematicBloc>(); // (8, 25)
	kenv.addFactory<CKPlaySoundCinematicBloc>(); // (8, 28)
	kenv.addFactory<CKPauseCinematicBloc>(); // (8, 29)
	kenv.addFactory<CKTeleportCinematicBloc>(); // (8, 30)
	kenv.addFactory<CKEndDoor>(); // (8, 31)
	kenv.addFactory<CKPlayVideoCinematicBloc>(); // (8, 34)
	kenv.addFactory<CKLockUnlockCinematicBloc>(); // (8, 36)


	// Dictionaries - Done
	kenv.addFactory<CAnimationDictionary>(); // (9, 1)
	kenv.addFactory<CTextureDictionary>(); // (9, 2)
	kenv.addFactory<CKSoundDictionary>(); // (9, 3)
	kenv.addFactory<CKSoundDictionaryID>(); // (9, 4)
	// kenv.addFactory<CKCameraAnimationDictionary>(); // (9, 83)


	// Geometries - Done
	kenv.addFactory<CKParticleGeometry>(); // (10, 1)
	kenv.addFactory<CKGeometry>(); // (10, 2)
	kenv.addFactory<CKSkinGeometry>(); // (10, 3)


	// Scene Nodes - Done
	kenv.addFactory<CSGRootNode>(); // (11, 1)
	kenv.addFactory<CSGSectorRoot>(); // (11, 2)
	kenv.addFactory<CNode>(); // (11, 3)
	kenv.addFactory<CSGAnchor>(); // (11, 4) - Not directly referenced in editor
	kenv.addFactory<CKDynBSphereProjectile>(); // (11, 6)
	kenv.addFactory<CSGLeaf>(); // (11, 8)
	kenv.addFactory<CSGBranch>(); // (11, 9)
	kenv.addFactory<CSGBkgRootNode>(); // (11, 10)
	kenv.addFactory<CGlowNodeFx>(); // (11, 11)
	kenv.addFactory<CClone>(); // (11, 12)
	kenv.addFactory<CKBoundingSphere>(); // (11, 14)
	kenv.addFactory<CKDynamicBoundingSphere>(); // (11, 15)
	kenv.addFactory<CKAABB>(); // (11, 17)
	kenv.addFactory<CKOBB>(); // (11, 18)
	kenv.addFactory<CParticlesNodeFx>(); // (11, 19)
	kenv.addFactory<CAnimatedNode>(); // (11, 21)
	kenv.addFactory<CKAACylinder>(); // (11, 24) - Not directly referenced in editor
	kenv.addFactory<CFogBoxNodeFx>(); // (11, 26)
	kenv.addFactory<CTrailNodeFx>(); // (11, 27)
	kenv.addFactory<CKPartlyUnknown<CNode, 28>>(); // (11, 28)
	kenv.addFactory<CSGLight>(); // (11, 32)
	kenv.addFactory<CCloudsNodeFx>(); // (11, 33) - Not directly referenced in editor
	kenv.addFactory<CZoneNode>(); // (11, 34)
	kenv.addFactory<CSpawnNode>(); // (11, 35)
	kenv.addFactory<CKPartlyUnknown<CKSceneNode, 37>>(); // (11, 37) Find class name - Not directly referenced in editor
	// (11, 68)
	kenv.addFactory<CKPartlyUnknown<CNode, 389>>(); // (11, 389) CKWaterNodeFx? - Double check this


	// Logic - Done
	// kenv.addFactory<CKGameLoop>(); // (12, 1)
	kenv.addFactory<CKPFGraphTransition>(); // (12, 2)
	kenv.addFactory<CKBundle>(); // (12, 3)
	kenv.addFactory<CKSector>(); // (12, 4)
	kenv.addFactory<CKLevel>(); // (12, 5)
	// kenv.addFactory<CKSavingManager>(); // (12, 6)
	// kenv.addFactory<CKLoadingManager>(); // (12, 7)
	// kenv.addFactory<CKCameraSector>(); // (12, 8)
	kenv.addFactory<CKCoreManager>(); // (12, 9)
	// kenv.addFactory<CKBlurFxData>(); // (12, 10)
	kenv.addFactory<CKSpline4>(); // (12, 11)
	// kenv.addFactory<CKBlurNodeFx>(); // (12, 12)
	// kenv.addFactory<CKChoreoKey>(); // (12, 15)
	kenv.addFactory<CKPFGraphNode>(); // (12, 16)
	kenv.addFactory<CKSas>(); // (12, 17) - Not directly referenced in editor
	kenv.addFactory<CGround>(); // (12, 18)
	kenv.addFactory<CDynamicGround>(); // (12, 19)
	kenv.addFactory<CKFlaggedPath>(); // (12, 23)
	// kenv.addFactory<CKChoreography>(); // (12, 27)
	kenv.addFactory<CKSpline4L>(); // (12, 31)
	// kenv.addFactory<CKCinematicScene>(); // (12, 37)
	// (12, 41)
	// kenv.addFactory<CKCinematicSceneData>(); // (12, 42)
	kenv.addFactory<CKVibrationData>(); // (12, 51)
	kenv.addFactory<CLocManager>(); // (12, 59)
	// kenv.addFactory<CKHDRFxData>(); // (12, 60)
	// kenv.addFactory<CKSekens>(); // (12, 61)
	kenv.addFactory<CKHDRNodeFx>(); // (12, 62)
	kenv.addFactory<CKMeshKluster>(); // (12, 66)
	// (12, 68)
	kenv.addFactory<CKBeaconKluster>(); // (12, 73)
	// kenv.addFactory<CKProjectileTypeScrap>(); // (12, 77)
	// kenv.addFactory<CKProjectileTypeBallisticPFX>(); // (12, 80)
	kenv.addFactory<CKFlashNode2dFx>(); // (12, 87)
	// kenv.addFactory<CKFlashFxData>(); // (12, 92)
	// kenv.addFactory<CKActivationFxData>(); // (12, 98)
	// kenv.addFactory<CKQuadTreeRoot>(); // (12, 99)
	// kenv.addFactory<CKQuadTreeLeaf>(); // (12, 100)
	kenv.addFactory<CKFilterNode2dFx>(); // (12, 103)
	// kenv.addFactory<CKFilterFxData>(); // (12, 104)
	// kenv.addFactory<CKExplosionNodeFx>(); // (12, 105)
	// kenv.addFactory<CKExplosionFxData>(); // (12, 106)
	// kenv.addFactory<CKQuadTreeBranch>(); // (12, 107)
	// kenv.addFactory<CKProjectileTypeSplineLock>(); // (12, 117)
	// kenv.addFactory<CKProjectileAccessor>(); // (12, 120)
	// kenv.addFactory<CKParticlesEffectNodeFx>(); // (12, 127)
	// kenv.addFactory<CKParticlesEffectFxData>(); // (12, 131)
	kenv.addFactory<CKTimeCounter>(); // (12, 135)
	kenv.addFactory<CKIntegerCounter>(); // (12, 136)
	kenv.addFactory<CKCombiner>(); // (12, 139)
	kenv.addFactory<CKComparator>(); // (12, 140)
	kenv.addFactory<CKComparedData>(); // (12, 141)
	kenv.addFactory<CKTrigger>(); // (12, 142)
	// kenv.addFactory<CKSparkNodeFx>();// (12, 145)
	// kenv.addFactory<CKSparkFxData>(); // (12, 147)
	// kenv.addFactory<CKAccessorPointerInfoData>(); // (12, 153) - Why 2 classes with the same ID??
	// kenv.addFactory<CKTimeScalingFxData>(); // (12, 153) - Why 2 classes with the same ID??
	kenv.addFactory<CKDetectorBase>(); // (12, 156) - Not directly referenced in editor
	kenv.addFactory<CKSectorDetector>(); // (12, 157)
	kenv.addFactory<CMultiGeometry>(); // (12, 158)
	// kenv.addFactory<CKTimeScalingNodeFx>(); // (12, 159)
	kenv.addFactory<CKDetectorEvent>(); // (12, 160)
	kenv.addFactory<CKDetectedMovable>(); // (12, 161)
	kenv.addFactory<CKTriggerDomain>(); // (12, 163)
	// kenv.addFactory<CKSound>(); // (12, 171)
	kenv.addFactory<CSGHotSpot>(); // (12, 173)
	// kenv.addFactory<CMaterial>(); // (12, 175)
	// kenv.addFactory<CKSrvFxParticlesAccessor>(); // (12, 176)
	// kenv.addFactory<CKBonusConfigTypeCone>(); // (12, 180)
	kenv.addFactory<CKMusicPlayList>(); // (12, 187)
	kenv.addFactory<CKDetectorMusic>(); // (12, 189)
	// kenv.addFactory<CKBonusConfigTypeStar>(); // (12, 190)
	kenv.addFactory<CMultiGeometryBasic>(); // (12, 197)
	// (12, 214)
	// kenv.addFactory<CKQuakeCpnt>(); // (12, 217) - Feels like this should be group 6?
	kenv.addFactory<CKDistortionNodeFx>(); // (12, 227)
	// kenv.addFactory<CKDistortionFxData>(); // (12, 229)
	// kenv.addFactory<CKCameraFogDatas>(); // (12, 233)
	// kenv.addFactory<CKWaterWaveFxData>();// (12, 238)
	// kenv.addFactory<CKWaterSplashFxData>(); // (12, 240)
	// kenv.addFactory<CKInputIconNodeFx>(); // (12, 278)
	// kenv.addFactory<CKInputIconFxData>(); // (12, 279)
	if (kenv.platform == kenv.PLATFORM_WII)
	{
		// NOTE: These may not be Wii specific
		// kenv.addFactory<CKTargetCursorNodeFx>(); // (12, 280)
		// kenv.addFactory<CKTargetCursorFxData>(); // (12, 281)
	}
	// kenv.addFactory<CKPxContainer>(); // (12, 283)
	// kenv.addFactory<CKLinkedBeaconSeq>(); // (12, 296)
	// kenv.addFactory<CKPxContactJoint>(); // (12, 308)
	// kenv.addFactory<CKWave>(); // (12, 323)
	kenv.addFactory<CKTriggerSynchro>(); // (12, 347)
	kenv.addFactory<CKStreamObject>(); // (12, 361)
	kenv.addFactory<CKStreamWave>(); // (12, 362)
	kenv.addFactory<CKDisplayBox>(); // (12, 385)
	// kenv.addFactory<CKInputAnchor>(); // (12, 389)
	// kenv.addFactory<CKOutputAnchor>(); // (12, 390)
	// kenv.addFactory<CKInputBlockSequential>(); // (12, 393)
	// kenv.addFactory<CKSekensBlock>(); // (12, 407)
	// kenv.addFactory<CKSekensMarker>(); // (12, 408)
	// (12, 411)
	// kenv.addFactory<CKTrcText>(); // (12, 417)
	// kenv.addFactory<CKStdText>(); // (12, 418)
	// kenv.addFactory<CKLoxSpeaker>(); // (12, 419)
	// kenv.addFactory<CKAlicePlayer>(); // (12, 480)
	// kenv.addFactory<CKAliceGameManager>(); // (12, 481)
	// kenv.addFactory<CKAliceGameLevel>(); // (12, 482)
	// kenv.addFactory<CKAliceGameModule>(); // (12, 483)
	// kenv.addFactory<CKAliceGameSpawnPoint>(); // (12, 484)
	kenv.addFactory<CKAliceGameState>(); // (12, 485)
	// kenv.addFactory<CKAliceGameStructure>(); // (12, 486)
	// kenv.addFactory<CKAliceInGameInterfaceCenter>(); // (12, 487)
	// kenv.addFactory<CKCameraConstraint>(); // (12, 508)
	// kenv.addFactory<CKDOFNodeFx>(); // (12, 511)
	// kenv.addFactory<CKAnimationMarkContainer>(); // (12, 550)
	// kenv.addFactory<CKMoveCpnt>(); // (12, 602) - Feels like this should be group 6?
	// kenv.addFactory<CKDamage>(); // (12, 603)
	// kenv.addFactory<CKAimCamembert>(); // (12, 621)
	// kenv.addFactory<CKBhvBlockAnimation>(); // (12, 628)
	// kenv.addFactory<CKNPCBehaviourBlockUser>(); // (12, 635)
	// kenv.addFactory<CKKLBCharacterHero>(); // (12, 637)
	// kenv.addFactory<CKMeshPopNodeFx>(); // (12, 649)
	// kenv.addFactory<CKMeshPopFxData>(); // (12, 650)
	// kenv.addFactory<CKCrumblyZoneElement>(); // (12, 652)
	// kenv.addFactory<CKCrumblyZoneState>(); // (12, 656)
	// kenv.addFactory<CKProjectileDataTypeBallisticPFX>(); // (12, 663)
	// kenv.addFactory<CKProjectileDataTypeScrap>(); // (12, 667)
	// kenv.addFactory<CKTransformationCpnt>(); // (12, 672)  - Feels like this should be group 6?
	// kenv.addFactory<CKGaugeCpnt>(); // (12, 673) - Feels like this should be group 6?
	// kenv.addFactory<CKControlableHero>(); // (12, 674)
	// kenv.addFactory<CKAliceGameLevelCollectible>(); // (12, 675)
	// kenv.addFactory<CKMarkedSoundDico>(); // (12, 684)
	// kenv.addFactory<CKMarkedFX>(); // (12, 685)
	// kenv.addFactory<CKActivationNodeFx>(); // (12, 725)
	// kenv.addFactory<CKInputCommandBinary>(); // (12, 729)
	// kenv.addFactory<CKInputCommandAnalogic>(); // (12, 730)
	// kenv.addFactory<CKInputActionButton>(); // (12, 731)
	// kenv.addFactory<CKInputCommandConditionBinary>(); // (12, 733)
	// kenv.addFactory<CKInputCommandConditionAnalogic>(); // (12, 734)
	// kenv.addFactory<CKInputCommandListOR>(); // (12, 736)
	// kenv.addFactory<CKInputCommandListTHEN>(); // (12, 737)
	// kenv.addFactory<CKGameUIPanel>(); // (12, 746)
	// kenv.addFactory<CKGameUICtrlLabel>(); // (12, 748)
	// kenv.addFactory<CKGameUIManager>(); // (12, 752)
	// kenv.addFactory<CKGameUIPage>(); // (12, 754)
	// kenv.addFactory<CKGameUICtrlButton>(); // (12, 756)
	// kenv.addFactory<CKGameUIActionNavigate>(); // (12, 761)
	// kenv.addFactory<CKGameUIActionOpenPage>(); // (12, 764)
	// kenv.addFactory<CKGameUIActionSetLabelText>(); // (12, 765)
	// kenv.addFactory<CKGameUIVariableLinkInteger>(); // (12, 767)
	// kenv.addFactory<CKGameUIVariableLinkLocText>(); // (12, 768)
	// kenv.addFactory<CKGameUIActionDefaultSelect>(); // (12, 769)
	// kenv.addFactory<CKAliceEnemyAttack>(); // (12, 775)
	// kenv.addFactory<CKGameUITheme>(); // (12, 780)
	// kenv.addFactory<CKGameUIBehaviourLabel>(); // (12, 781)
	// kenv.addFactory<CKGameUIBehaviourButton>(); // (12, 782)
	// kenv.addFactory<CKGameUIBehaviourPanel>(); // (12, 784)
	// kenv.addFactory<CKGameUIBhvUpdaterButton>(); // (12, 786)
	// kenv.addFactory<CKGameUIBhvUpdaterLabel>(); // (12, 787)
	// kenv.addFactory<CKGameUIBhvUpdaterPanel>(); // (12, 788)
	// kenv.addFactory<CKGameUIEventInput>(); // (12, 795)
	// kenv.addFactory<CKGameUIEventAction>(); // (12, 796)
	// kenv.addFactory<CKGameUIActionChangeVariableLinkInteger>(); // (12, 799)
	// kenv.addFactory<CKAnimatedMove>(); // (12, 800)
	// kenv.addFactory<CKGameUITriggerActionInput>(); // (12, 802)
	// kenv.addFactory<CKGameUITriggerActionCtrlState>(); // (12, 803)
	// kenv.addFactory<CKGameUIVariableLinkAliceMap>(); // (12, 805)
	// kenv.addFactory<CKGameUIBehaviourAliceMap>(); // (12, 806)
	// kenv.addFactory<CKGameUIBhvUpdaterAliceMap>(); // (12, 807)
	// kenv.addFactory<CKGameUICtrlAliceMap>(); // (12, 808)
	// kenv.addFactory<CKFootprintNodeFx>(); // (12, 809)
	// kenv.addFactory<CKFootprintFxData>(); // (12, 810)
	// kenv.addFactory<CKGameUIActionGameManager>(); // (12, 812)
	// kenv.addFactory<CKGameUICtrlGauge>(); // (12, 819)
	// kenv.addFactory<CKSplineNodeFx>(); // (12, 820)
	// kenv.addFactory<CKGameUIBehaviourGauge>(); // (12, 821)
	// kenv.addFactory<CKSplineFxData>(); // (12, 822)
	// kenv.addFactory<CKGameUIBhvUpdaterGauge>(); // (12, 823)
	// kenv.addFactory<CKAliceGameUIActionIID>(); // (12, 829)
	// kenv.addFactory<CKGameUIActionOnMemcard>(); // (12, 832)
	// kenv.addFactory<CKGameUICtrlMemcardSlot>(); // (12, 833)
	// kenv.addFactory<CKGameUIActionMessageBoxReturn>(); // (12, 834)
	// kenv.addFactory<CKGameUIBehaviourMemcardSlot>(); // (12, 835)
	// kenv.addFactory<CKGameUIBhvUpdaterMemcardSlot>(); // (12, 836)
	// kenv.addFactory<CKGameUIActionChangeSelection>(); // (12, 842)
	// kenv.addFactory<CKGameUIActionEnableObject>(); // (12, 843)
	// kenv.addFactory<CKGameUIVariableLinkBoolean>(); // (12, 845)
	// kenv.addFactory<CKAliceGameUIActionPauseInfo>(); // (12, 848)
	// kenv.addFactory<CKGameUICtrlMultiTextureDisplay>(); // (12, 850)
	// kenv.addFactory<CKGameUIBehaviourMultiTextureDisplay>(); // (12, 852)
	// kenv.addFactory<CKGameUIBhvUpdaterMultiTextureDisplay>(); // (12, 853)
	// kenv.addFactory<CKGameUIVariableLinkUnsignedInteger>(); // (12, 854)
	// kenv.addFactory<CKAliceGameUIActionChangePlayer>(); // (12, 855)
	// kenv.addFactory<CKGameUIBehaviourInventorySlot>(); // (12, 864)
	// kenv.addFactory<CKGameUIBhvUpdaterInventorySlot>(); // (12, 865)
	// kenv.addFactory<CKGameUICtrlVideo>(); // (12, 869)
	// kenv.addFactory<CKAliceGameObjective>(); // (12, 871)
	// kenv.addFactory<CKGameUIActionOnVideo>(); // (12, 873)
	// kenv.addFactory<CKGameUIBhvUpdaterButtonShape>(); // (12, 876)
	// kenv.addFactory<CKExtendedTexture>(); // (12, 877)
	// kenv.addFactory<CKExtendedTextureCollection>(); // (12, 878)
	// kenv.addFactory<CKGameUIActionTriggerStarter>(); // (12, 879)
	// kenv.addFactory<CKInputCommandRepeat>(); // (12, 890)
	// kenv.addFactory<CKInputActionMashing>(); // (12, 891)
	// kenv.addFactory<CKGameUIVariableLinkVector2>(); // (12, 892)
	// kenv.addFactory<CKGameUICtrlToolTip>(); // (12, 893)
	// kenv.addFactory<CKGameUIBhvUpdaterToolTip>(); // (12, 895)
	// kenv.addFactory<CKGameUIBhvUpdateColorPalette>(); // (12, 900)
	// kenv.addFactory<CKGameUIBhvUpdaterInfoLine>(); // (12, 903)
	// kenv.addFactory<CKGameUICtrlLabelButton>(); // (12, 907)
	// kenv.addFactory<CKGameUIBehaviourLabelButton>(); // (12, 908)
	// kenv.addFactory<CKGameUIBhvUpdaterLabelButton>(); // (12, 909)
	// kenv.addFactory<CKAliceInventory>(); // (12, 910)
	// kenv.addFactory<CKAliceInventoryItem>(); // (12, 911)
	// kenv.addFactory<CKAliceGameUIVariableLinkInventory>(); // (12, 916)
	// kenv.addFactory<CKConfigAnimDicoManager>(); // (12, 919)
	// kenv.addFactory<CKQuickTimeEventValidation>(); // (12, 922)
	// kenv.addFactory<CKInputActionAnalogic>(); // (12, 926)
	// kenv.addFactory<CKGameUIBhvUpdaterAliceSwapMenu>(); // (12, 929)
	// kenv.addFactory<CKGameUIBehaviourLabelCounter>(); // (12, 930)
	// kenv.addFactory<CKGameUICtrlLabelCounter>(); // (12, 931)
	// kenv.addFactory<CKGameUIBhvUpdaterLabelCounter>(); // (12, 932)
	// kenv.addFactory<CKAliceLandmarkCollection>(); // (12, 933)
	// kenv.addFactory<CKAliceLandmark>(); // (12, 934)
	// kenv.addFactory<CKAliceGameUIBhvUpdaterIconPool>(); // (12, 937)
	// kenv.addFactory<CKGameUIActionChangeVariableLinkBoolean>(); // (12, 954)
	// kenv.addFactory<CKAliceGameUICtrlInventorySlot>(); // (12, 957)
	// kenv.addFactory<CKAliceGameUIBhvUpdaterInventorySlot>(); // (12, 958)
	// kenv.addFactory<CKAliceGameUIBehaviourInventorySlot>(); // (12, 959)
	// kenv.addFactory<CKAliceStringRepresent>(); // (12, 972)
	// kenv.addFactory<CKAliceStringSlot>();// (12, 973)
	// kenv.addFactory<CKAliceStringSlotCollection>(); // (12, 974)
	// kenv.addFactory<CKAliceGameUIActionApplyOptions>(); // (12, 975)
	// kenv.addFactory<CKAliceGameUIActionDefaultSoundOptions>(); // (12, 976)
	// kenv.addFactory<CKAliceGameUIActionApplySoundOptions>(); // (12, 977)
	// kenv.addFactory<CKAliceGameUIActionDefaultOptions>(); // (12, 978)
	// kenv.addFactory<CKAliceGameUIActionOptionsModified>(); // (12, 979)
	// kenv.addFactory<CKAliceGameUIActionSoundOptionsModified>(); // (12, 980)
	// kenv.addFactory<CKAliceHeroAbilityConfigThrowOff>(); // (12, 998)
	// kenv.addFactory<CKAliceWorldToMapTransform>(); // (12, 999)
	// kenv.addFactory<CKHkAnimSequenceActor>(); // (12, 1000)
	// kenv.addFactory<CKAliceGameUIActionLoading>(); // (12, 1011)
	// kenv.addFactory<CKGameUIActionLaunchAnimation>(); // (12, 1016)
	// kenv.addFactory<CKPerspDistortionNodeFx>(); // (12, 1018)
	// kenv.addFactory<CKPerspDistortionFxData>(); // (12, 1019)
	// kenv.addFactory<CKAliceStringContextual>(); // (12, 1027)
	// kenv.addFactory<CKCrumblyZoneBounding>(); // (12, 1028)
	// kenv.addFactory<CKGameUIActionOnCinematic>(); // (12, 1029)
	// kenv.addFactory<CKAliceAchievement>(); // (12, 1031)
	// kenv.addFactory<CKAliceGameUIActionLoadingRefused>(); // (12, 1033)
	// kenv.addFactory<CKAliceGameUIActionUnlockCharacters>();// (12, 1040)
	// kenv.addFactory<CKAliceGameUIActionUnlockUpgrades>();// (12, 1041)
	// kenv.addFactory<CKGameUIActionChangeVariableLinkInteger>(); // (12, 1047)
	// kenv.addFactory<CKGameUICtrlKeyboardMap>(); // (12, 1048)
	// kenv.addFactory<CKGameUIBehaviourKeyboardMap>(); // (12, 1049)
	// kenv.addFactory<CKGameUIBhvUpdaterKeyboardMap>(); // (12, 1050)
	// kenv.addFactory<CKGameUIActionSetLabelTextForLabelButton>(); // (12, 1074)
	// kenv.addFactory<CKGameUIActionControlMapping>();// (12, 1075)
	// kenv.addFactory<CKGameUIBhvUpdaterMultiLabel>(); // (12, 1081)
	// kenv.addFactory<CKGameUIBehaviourMultiLabel>(); // (12, 1082)
	// kenv.addFactory<CKGameUICtrlMultiLabel>(); // (12, 1083)
	// kenv.addFactory<CKGameUIActionStartMultiLabel>(); // (12, 1084)
	// kenv.addFactory<CKStreamRTXFCLauncher>(); // (12, 1085)
	// kenv.addFactory<CKGameUIActionExitGame>(); // (12, 1087)
	// kenv.addFactory<CKGameUICtrlAssignInputPC>(); // (12, 1088)
	// kenv.addFactory<CKGameUIActionPlaySound>(); // (12, 1090)


	// Graphical - Done
	// kenv.addFactory<CRenderer>(); // (13, 1)
	kenv.addFactory<CCloneManager>(); // (13, 3)
	// kenv.addFactory<CAnimationManager>(); // (13, 8)
	// (13, 10)
	kenv.addFactory<CKPBuffer>(); // (13, 13)
	// (13, 14)
	kenv.addFactory<CBillboard2d>(); // (13, 15)
	// kenv.addFactory<CManager2d>(); // (13, 16)
	// (13, 17)
	// (13, 19)
	// (13, 20)
	// (13, 21)
	// (13, 23)
	kenv.addFactory<CKSpawnPoolParams>(); // (13, 24)
	// (13, 26)
	kenv.addFactory<CKFlashUI>(); // (13, 27)
	kenv.addFactory<CKFlashManager>(); // (13, 28)
	kenv.addFactory<CKFlashText>(); // (13, 31)
	kenv.addFactory<CLightManager>(); // (13, 36)
	kenv.addFactory<CLightSet>(); // (13, 37)
	// (13, 39)
	if (kenv.platform == kenv.PLATFORM_PC)
	{
		// kenv.addFactory<WIN32_CKVideo>(); // (13, 41)
	}
	else if (kenv.platform == kenv.PLATFORM_WII)
	{
		// kenv.addFactory<Revolution_CKVideo>(); // (13, 41)
	}
	// kenv.addFactory<CKAnmKeyFrameController>();// (13, 45)
	// (13, 46)
	kenv.addFactory<CKSpawnPool>(); // (13, 47)
	// (13, 49)
	// (13, 50)
	// (13, 51)
	// (13, 52)
	// kenv.addFactory<CKBlenderController>();// (13, 53)
	// kenv.addFactory<CKVideoSegment>(); // (13, 54)
	// kenv.addFactory<CSectorAnimation>(); // (13, 55)
	// (13, 57)
	// (13, 67)
	// (13, 78)
	// kenv.addFactory<CKGameUIRendable>(); // (13, 81)
	// (13, 87)
	// (13, 109)
	// (13, 308)
}

static void registerClassesForHTTYD(KEnvironment& kenv)
{
	kenv.addFactory<CKServiceManager>();
	kenv.addFactory<CKSoundManager>();
	kenv.addFactory<CKServiceLife>();
	kenv.addFactory<CKSrvCollision>();
	kenv.addFactory<CKSrvCinematic>();
	kenv.addFactory<CKSrvPathFinding>();
	kenv.addFactory<CKSrvAvoidance>();
	kenv.addFactory<CKSrvSekensor>();
	kenv.addFactory<CKSrvBeacon>();
	kenv.addFactory<CKSrvProjectiles>();
	kenv.addFactory<CKSrvCounter>();
	kenv.addFactory<CKSrvTrigger>();
	kenv.addFactory<CKSrvDetect>();
	kenv.addFactory<CKSrvMusic>();
	kenv.addFactory<CAnimationDictionary>();
	kenv.addFactory<CTextureDictionary>();
	kenv.addFactory<CKSoundDictionaryID>();
	kenv.addFactory<CKParticleGeometry>();
	kenv.addFactory<CKGeometry>();
	kenv.addFactory<CKSkinGeometry>();
	kenv.addFactory<CSGRootNode>();
	kenv.addFactory<CSGSectorRoot>();
	kenv.addFactory<CNode>();
	kenv.addFactory<CKDynBSphereProjectile>();
	kenv.addFactory<CSGLeaf>();
	kenv.addFactory<CSGBranch>();
	kenv.addFactory<CGlowNodeFx>();
	kenv.addFactory<CClone>();
	kenv.addFactory<CKBoundingSphere>();
	kenv.addFactory<CKDynamicBoundingSphere>();
	kenv.addFactory<CKAABB>();
	kenv.addFactory<CKOBB>();
	kenv.addFactory<CParticlesNodeFx>();
	kenv.addFactory<CAnimatedNode>();
	kenv.addFactory<CAnimatedClone>();
	kenv.addFactory<CKAACylinder>();
	kenv.addFactory<CSkyNodeFx>();
	kenv.addFactory<CFogBoxNodeFx>();
	kenv.addFactory<CTrailNodeFx>();
	kenv.addFactory<CSGLight>();
	kenv.addFactory<CCloudsNodeFx>();
	kenv.addFactory<CZoneNode>();
	kenv.addFactory<CSpawnNode>();
	kenv.addFactory<CSpawnAnimatedNode>();
	kenv.addFactory<CSGAnchor>();
	kenv.addFactory<CSGBkgRootNode>();
	kenv.addFactory<CKPartlyUnknown<CNode, 28>>();
	kenv.addFactory<CKPartlyUnknown<CKSceneNode, 37>>();
	kenv.addFactory<CKPartlyUnknown<CNode, 389>>(); // CKWaterNodeFx
	kenv.addFactory<CKPFGraphTransition>();
	kenv.addFactory<CKBundle>();
	kenv.addFactory<CKSector>();
	kenv.addFactory<CKLevel>();
	kenv.addFactory<CKCoreManager>();
	kenv.addFactory<CKSpline4>();
	kenv.addFactory<CKPFGraphNode>();
	kenv.addFactory<CKSas>();
	kenv.addFactory<CGround>();
	kenv.addFactory<CDynamicGround>();
	kenv.addFactory<CKFlaggedPath>();
	kenv.addFactory<CKLine>();
	kenv.addFactory<CKSpline4L>();
	kenv.addFactory<CLocManager>();
	kenv.addFactory<CKMeshKluster>();
	kenv.addFactory<CKBeaconKluster>();
	kenv.addFactory<CKTimeCounter>();
	kenv.addFactory<CKIntegerCounter>();
	kenv.addFactory<CKCombiner>();
	kenv.addFactory<CKComparator>();
	kenv.addFactory<CKComparedData>();
	kenv.addFactory<CKTrigger>();
	kenv.addFactory<CKDetectorBase>();
	kenv.addFactory<CKSectorDetector>();
	kenv.addFactory<CMultiGeometry>();
	kenv.addFactory<CKDetectorEvent>();
	kenv.addFactory<CKDetectedMovable>();
	kenv.addFactory<CKTriggerDomain>();
	kenv.addFactory<CSGHotSpot>();
	kenv.addFactory<CKMusicPlayList>();
	kenv.addFactory<CKDetectorMusic>();
	kenv.addFactory<CMultiGeometryBasic>();
	kenv.addFactory<CKTriggerSynchro>();
	kenv.addFactory<CKStreamObject>();
	kenv.addFactory<CKStreamWave>();
	kenv.addFactory<CKDisplayBox>();
	kenv.addFactory<CCloneManager>();
	kenv.addFactory<CBillboard2d>();
	kenv.addFactory<CLightManager>();
	kenv.addFactory<CLightSet>();
	kenv.addFactory<CKTydGameState>();
	if (kenv.platform == kenv.PLATFORM_PC)
		kenv.addFactory<CKSoundDictionary>();
}

void ClassRegister::registerClasses(KEnvironment& kenv, int gameVersion, int gamePlatform, bool isRemaster)
{
	if (gameVersion <= KEnvironment::KVERSION_XXL1 && (gamePlatform == KEnvironment::PLATFORM_PC || gamePlatform == KEnvironment::PLATFORM_GCN)) {
		registerClassesForXXL1PC(kenv);
	}
	else if (gameVersion <= KEnvironment::KVERSION_XXL1) {
		registerClassesForXXL1Console(kenv);
	}
	else if (gameVersion == KEnvironment::KVERSION_ARTHUR) {
		registerClassesForArthur(kenv);
		if (gamePlatform == KEnvironment::PLATFORM_PC)
			kenv.addFactory<CKSoundDictionary>();
	}
	else if (gameVersion == KEnvironment::KVERSION_ALICE) {
		registerClassesForAlice(kenv);
	}
	else if (gameVersion == KEnvironment::KVERSION_HTTYD) {
		registerClassesForHTTYD(kenv);
	}
	else if (gamePlatform == KEnvironment::PLATFORM_PC) {
		registerClassesForXXL2PlusPC(kenv);
	}
	else {
		registerClassesForXXL2PlusConsole(kenv);
		if (gameVersion <= KEnvironment::KVERSION_OLYMPIC) {
			kenv.addFactory<CKHkBasicBonus>();
			kenv.addFactory<CKGrpSquadX2>();
			kenv.addFactory<CKGrpPoolSquad>();
			kenv.addFactory<CKGrpA2BonusPool>();
			kenv.addFactory<CKGrpBonusX2>();
			kenv.addFactory<CKGrpA3BonusPool>();
			kenv.addFactory<CKCrateCpnt>();
			kenv.addFactory<GameX2::CKGrpFightZone>();
			kenv.addFactory<GameOG::CKHkA3Enemy>();
			kenv.addFactory<GameOG::CKEnemySectorCpnt>();
		}
		if (gamePlatform == KEnvironment::PLATFORM_X360 || gamePlatform == KEnvironment::PLATFORM_PS3) {
			kenv.addFactory<CKSoundDictionary>();
		}
		if (gameVersion <= KEnvironment::KVERSION_OLYMPIC || gamePlatform != KEnvironment::PLATFORM_WII) {
			kenv.addFactory<CAnimationManager>();
			kenv.addFactory<CSectorAnimation>();
		}
	}
}
