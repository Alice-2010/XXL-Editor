#pragma once

#include <functional>

struct File;
struct KEnvironment;

struct CKObject {
	int refCount = 0;
	void addref() { refCount++; }
	void release() { refCount++; }
	virtual bool isSubclassOf(uint32_t fid) = 0;
	virtual int getClassCategory() = 0;
	virtual int getClassID() = 0;
	virtual void deserialize(KEnvironment* kenv, File *file, size_t length) = 0;
	virtual void serialize(File *file) = 0;
	virtual ~CKObject() {};

	bool isSubclassOf(int clcat, int clid) { return isSubclassOf(clcat | (clid << 6)); }
	uint32_t getClassFullID() { return getClassCategory() | (getClassID() << 6); }
};

struct CKUnknown : CKObject {
	static const int FULL_ID = -1;
	int clCategory, clId;
	void *mem = nullptr;
	size_t length = 0;

	bool isSubclassOf(uint32_t fid) override;
	int getClassCategory() override;
	int getClassID() override;
	void deserialize(KEnvironment* kenv, File *file, size_t length) override;
	void serialize(File *file) override;
	CKUnknown(int category, int id) : clCategory(category), clId(id) {}
	~CKUnknown();
};

struct KFactory {
	uint32_t fullid;
	std::function<CKObject*()> create;
	std::function<CKObject*(int)> createArray;

	KFactory() : fullid(~0) {}
	KFactory(uint32_t fullid, std::function<CKObject*()> create, std::function<CKObject*(int)> createArray) :
		fullid(fullid), create(create), createArray(createArray) {}

	template<class T> static KFactory of() {
		return KFactory(T::FULL_ID, []() -> T* {return new T; }, [](int n) -> T* {return new T[n]; });
	}
};

template<int T_CAT> struct CKCategory : CKObject {
	static const int CATEGORY = T_CAT;
	bool isSubclassOf(uint32_t fid) override { return fid == CATEGORY; }
	int getClassCategory() override { return CATEGORY; }
};

template<class T, int T_ID> struct CKSubclass : T {
	static const int CLASS_ID = T_ID;
	static const int FULL_ID = T::CATEGORY | (T_ID << 6);
	
	bool isSubclassOf(uint32_t fid) override {
		//printf("%i :: isSubclass(%i)\n", FULL_ID, fid);
		if (fid == FULL_ID)
			return true;
		return T::isSubclassOf(fid);
	}
	
	int getClassID() override { return T_ID; }
};

//template<class T> KFactory getFactory() {
//	return KFactory([]() -> T* {return new T; }, [](int n) -> T* {return new T[n]; });
//}

template<class T> struct objref {
	T *_pointer;
	T *operator->() { return _pointer; }
	T &operator*() { return *_pointer; }
	void reset(T *newpointer = nullptr) {
		if (_pointer)
			_pointer->release();
		_pointer = newpointer;
		if (_pointer)
			_pointer->addref();
	}
	objref() : _pointer(nullptr) {}
	objref(T *pointer) : _pointer(pointer) { _pointer->addref(); }
	objref(objref &another) : _pointer(another._pointer) { _pointer->addref(); }
	objref(objref &&another) : _pointer(another._pointer) { another._pointer = nullptr; }
	~objref() { if(_pointer) _pointer->release(); }
};

//struct CKManager : CKCategory<0> {};
//struct CKService : CKCategory<1> {};
//struct CKHook : CKCategory<2> {};
//struct CKHookLife : CKCategory<3> {};
//struct CKGroup : CKCategory<4> {};
//struct CKGroupLife : CKCategory<5> {};
//struct CKComponent : CKCategory<6> {};
//struct CKCamera : CKCategory<7> {};
//struct CKCinematicBloc : CKCategory<8> {};
//struct CKDictionary : CKCategory<9> {};
//struct CKGeometry : CKCategory<10> {};
//struct CKNode : CKCategory<11> {};
//struct CKLogic : CKCategory<12> {};
//struct CKGraphical : CKCategory<13> {};
//struct CKError : CKCategory<14> {};