#pragma once
#include <string>
#include "stdafx.h"

struct vec3
{
	float x, y, z;
};

struct vec4
{
	float x, y, z, w;
};

struct matrix44
{
	vec4 m[4];
};

#define MASK_KIND_RVALUE (0x0ffffff)
enum RValueType : int {
	VALUE_REAL = 0,
	VALUE_STRING = 1,
	VALUE_ARRAY = 2,
	VALUE_PTR = 3,
	VALUE_VEC3 = 4,
	VALUE_UNDEFINED = 5,
	VALUE_OBJECT = 6,
	VALUE_INT32 = 7,
	VALUE_VEC4 = 8,
	VALUE_MATRIX = 9,
	VALUE_INT64 = 10,
	VALUE_ACCESSOR = 11,
	VALUE_JSNULL = 12,
	VALUE_BOOL = 13,
	VALUE_ITERATOR = 14,
	VALUE_REF = 15,
	VALUE_UNSET = MASK_KIND_RVALUE
};

class YYObjectBase;
typedef YYObjectBase*(*GetCtxStackTop)(void);
typedef void(*DetPotRoot)(YYObjectBase* _pContainer, YYObjectBase* _pObject);
extern GetCtxStackTop GetContextStackTop;
extern DetPotRoot DeterminePotentialRoot;

struct RValue;
typedef void(*FREE_RVal_Pre)(RValue* p);
typedef void(*YYSetStr)(RValue* _pVal, const char* _pS);
typedef void(*YYCreStr)(RValue* _pVal, const char* _pS);
typedef char*(*YYDupStr)(const char* _pStr);
typedef char*(*YYStrDupT)(const char* _pS);
typedef void(*YYFreeT)(void* _pMemory);
typedef RValue*(*ARRAYLVal)(RValue* _pV, int _index);
extern YYSetStr YYSetString;
extern YYCreStr YYCreateString;
extern YYStrDupT YYStrDup;
extern YYFreeT YYFree;
extern FREE_RVal_Pre FREE_RValue__Pre;
extern ARRAYLVal ARRAY_LVAL_RValue;

template <typename T> struct _RefFactory
{
	static T Alloc(T _thing, int _size) { return _thing; }
	static T Create(T _thing, int& _size) { _size = 0; return _thing; }
	static T Destroy(T _thing) { return _thing; }
};

template <> struct _RefFactory< const char* >
{
	static const char* Alloc(const char* _thing, int _size) { abort(); return nullptr; }
	static const char* Create(const char* _thing, int& _size) { _size = _thing ? (int)strlen(_thing) : 0; return YYStrDup(_thing); }
	static const char* Destroy(const char* _thing) { YYFree(reinterpret_cast<void*>(const_cast<char*>(_thing))); return nullptr; }
};

template <typename T> struct _RefThing
{
	T		m_thing;
	int		m_refCount;
	int		m_size;

	_RefThing(int _maxSize) {
		// this needs to have some sort of factory based on the type to do a duplicate
		m_thing = _RefFactory<T>::Alloc(m_thing, _maxSize);
		m_size = _maxSize;
		m_refCount = 0;
		inc();
	}

	_RefThing(T _thing) {
		// this needs to have some sort of factory based on the type to do a duplicate
		m_thing = _RefFactory<T>::Create(_thing, m_size);
		m_refCount = 0;
		inc();
	}

	~_RefThing() {
		dec();
	}

	void inc(void) {
		++m_refCount;
	} // end Inc

	void dec(void) {
		--m_refCount;
		if (m_refCount == 0) {
			// use the factory to clean it up and give us a default thing to use
			m_thing = _RefFactory<T>::Destroy(m_thing);
			m_size = 0;
			delete this;
		} // end if
	} // end Dec

	T   get(void)  const { return m_thing; }
	int size(void) const { return m_size;  }

	static _RefThing<T>* assign(_RefThing<T>* _other) { if (_other != nullptr) { _other->inc(); } return _other;  }
	static _RefThing<T>* remove(_RefThing<T>* _other) { if (_other != nullptr) { _other->dec(); } return nullptr; }
};

typedef _RefThing<const char*> RefString;

struct DynamicArrayOfRValue
{
	int length;
	RValue* arr;
};

struct RefDynamicArrayOfRValue
{
	int	refcount;
	DynamicArrayOfRValue* pArray;
	RValue* pOwner;
	int visited;
	int length;
};

#define VARIABLE_ARRAY_MAX_DIMENSION (32000)
#define ARRAY_INDEX_NO_INDEX         (INT_MIN)

#pragma pack(push, 4)
struct RValue
{
	union {
		// values.
		int v32;
		long long v64;
		double val;						// value when real

		// pointers.
		void* ptr;
		RefString* pRefString;
		RefDynamicArrayOfRValue* pRefArray;
		YYObjectBase* pObj;
		vec4* pVec4;
		matrix44* pMatrix44;
	};
	int flags; // use for flags (Hijack for Enumerable and Configurable bits in JavaScript)  (Note: probably will need a visibility as well, to support private variables that are promoted to object scope, but should not be seen (is that just not enumerated????) )
	int kind; // kind of value

	void __localFree(void);
	void __localCopy(const RValue& v);

	~RValue();

	RValue();
	RValue(const RValue& v);

	RValue(double v);
	RValue(float v);
	RValue(int v);
	RValue(long long v);
	RValue(bool v);
	RValue(std::nullptr_t);
	RValue(std::nullptr_t, bool undefined);
	RValue(void* v);
	RValue(const char* v);
	RValue(std::string v);
	RValue(std::wstring v);

	RValue operator-();
	RValue operator+();

	RValue& operator=(const RValue& v);
	RValue& operator=(double v);
	RValue& operator=(float v);
	RValue& operator=(int v);
	RValue& operator=(long long v);
	RValue& operator=(void* v);
	RValue& operator=(bool v);
	RValue& operator=(const char* v);
	RValue& operator=(std::string v);
	RValue& operator=(std::wstring v);

	RValue& operator++();
	RValue  operator++(int);

	RValue& operator--();
	RValue  operator--(int);

	bool operator==(const RValue& rhs) const;
	bool operator!=(const RValue& rhs) const;

	const RValue& DoArrayIndex(const int _index);
	const RValue& operator[](const int _index);
	RValue& operator()(const int _index);

	std::string asString() const;
	double asReal() const;
	int asInt32() const;
	bool asBoolean() const;
	long long asInt64() const;
	void* asPointer() const;
	const DynamicArrayOfRValue* asArray() const;
	bool isNumber() const;
	bool isUnset() const;
	bool isArray() const;

	operator double() const;
	operator int() const;
	operator long long() const;
	operator bool() const;
	operator std::string();
	operator void*() const;
	//operator const DynamicArrayOfRValue*() const;
};

class CInstanceBase;
typedef bool(*TGetVarRoutine)(CInstanceBase* obj, int array_index, RValue* res);
typedef bool(*TSetVarRoutine)(CInstanceBase* obj, int array_index, RValue* val);
struct RVariableRoutine
{
	char* f_name;
	TGetVarRoutine f_getroutine;
	TSetVarRoutine f_setroutine;
	bool f_canset;
};

extern RVariableRoutine* g_BuiltinVars;

class YYObjectBase;
typedef int(*AllocNewVarSlotT)(YYObjectBase* obj, const char* name);
extern AllocNewVarSlotT Code_Variable_FindAlloc_Slot_From_Name;

#pragma pack(pop)
