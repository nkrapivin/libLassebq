#include "RValue.h"
#include <sstream>

GetCtxStackTop GetContextStackTop = nullptr;
DetPotRoot DeterminePotentialRoot = nullptr;
FREE_RVal_Pre FREE_RValue__Pre = nullptr;
YYSetStr YYSetString = nullptr;
YYCreStr YYCreateString = nullptr;
YYAddStr YYAddString = nullptr;
YYStrDupT YYStrDup = nullptr;
YYFreeT YYFree = nullptr;
ARRAYLVal ARRAY_LVAL_RValue = nullptr;
RVariableRoutine* g_BuiltinVars = nullptr;

void RValue::__localFree()
{
	if (((kind - 1) & (MASK_KIND_RVALUE & (~VALUE_PTR))) == 0) {
		FREE_RValue__Pre(this);
	}
}

void RValue::__localCopy(const RValue& v)
{
	this->kind = v.kind;
	this->flags = v.flags;

	switch (v.kind & MASK_KIND_RVALUE) {
		case VALUE_BOOL:
		case VALUE_REAL:
			this->val = v.val;
			break;
		case VALUE_INT32:
			this->v32 = v.v32;
			break;
		case VALUE_INT64:
			this->v64 = v.v64;
			break;
		case VALUE_PTR:
		case VALUE_ITERATOR:
			this->ptr = v.ptr;
			break;
		case VALUE_ARRAY:
			this->pRefArray = v.pRefArray;
			if (this->pRefArray != nullptr) {
				++this->pRefArray->refcount;
				if (this->pRefArray->pOwner == nullptr) {
					this->pRefArray->pOwner = const_cast<RValue*>(&v);
				}
			}
			break;
		case VALUE_STRING:
			this->pRefString = RefString::assign(v.pRefString);
			break;
		case VALUE_OBJECT:
			this->pObj = v.pObj;

			if (this->pObj != nullptr) {
				YYObjectBase* pContainer = GetContextStackTop();
				DeterminePotentialRoot(pContainer, v.pObj);
			}
			break;
	}
}

RValue::~RValue()
{
	__localFree();
	flags = 0;
	kind = VALUE_UNSET;
	v64 = 0L;
}

RValue::RValue()
{
	flags = 0;
	kind = VALUE_UNSET;
	v64 = 0L;
}

RValue::RValue(std::nullptr_t, bool undefined)
{
	flags = 0;
	kind = VALUE_UNDEFINED;
	v64 = 0L;
}

RValue::RValue(const RValue& v)
{
	__localCopy(v);
}

RValue::RValue(double v)
{
	flags = 0;
	kind = VALUE_REAL;
	val = v;
}

RValue::RValue(float v)
{
	flags = 0;
	kind = VALUE_REAL;
	val = v;
}

RValue::RValue(int v)
{
	flags = 0;
	kind = VALUE_REAL;
	val = v;
}

RValue::RValue(long long v)
{
	flags = 0;
	kind = VALUE_INT64;
	v64 = v;
}

RValue::RValue(bool v)
{
	flags = 0;
	kind = VALUE_REAL;
	val = v ? 1.0 : 0.0;
}

RValue::RValue(std::nullptr_t v)
{
	flags = 0;
	kind = VALUE_PTR;
	ptr = nullptr;
}

RValue::RValue(void* v)
{
	flags = 0;
	kind = VALUE_PTR;
	ptr = v;
}

RValue::RValue(const char* v)
{
	flags = 0;
	YYSetString(this, v);
}

RValue::RValue(std::string v)
{
	flags = 0;
	YYSetString(this, v.c_str());
}

RValue::RValue(std::wstring v)
{
	flags = 0;
	int __size = WideCharToMultiByte(CP_UTF8, 0, v.c_str(), -1, nullptr, 0, nullptr, nullptr);
	char* s = new char[__size];

	WideCharToMultiByte(CP_UTF8, 0, v.c_str(), -1, s, __size, nullptr, nullptr);

	YYSetString(this, s);
	delete[] s;
	s = nullptr;
}

RValue RValue::operator-()
{
	RValue ret;
	ret.kind = kind;
	ret.flags = flags;
	switch ((kind & MASK_KIND_RVALUE)) {
		case VALUE_BOOL:
		case VALUE_REAL: ret.val = -val; break;
		case VALUE_INT32: ret.v32 = -v32; break;
		case VALUE_INT64: ret.v64 = -v64; break;
		default: abort();
	}

	return ret;
}

RValue RValue::operator+()
{
	// does nothing :/ just makes a copy of the value.
	RValue copy(*this);
	return copy;
}

RValue& RValue::operator=(const RValue& v)
{
	if (&v != this)
	{
		RValue temp;
		memcpy(&temp, &v, sizeof(RValue));
		bool fIsArray = (temp.kind & MASK_KIND_RVALUE) == VALUE_ARRAY;
		if (fIsArray) ++(temp.pRefArray->refcount);
		__localFree();
		if (fIsArray) --(temp.pRefArray->refcount);
		__localCopy(temp);
	}

	return *this;
}

RValue& RValue::operator=(double v)
{
	__localFree();
	kind = VALUE_REAL;
	val = v;
	return *this;
}

RValue& RValue::operator=(float v)
{
	__localFree();
	kind = VALUE_REAL;
	val = v;
	return *this;
}

RValue& RValue::operator=(int v)
{
	__localFree();
	kind = VALUE_REAL;
	val = v;
	return *this;
}

RValue& RValue::operator=(long long v)
{
	__localFree();
	kind = VALUE_INT64;
	v64 = v;
	return *this;
}

RValue& RValue::operator=(void* v)
{
	__localFree();
	kind = VALUE_PTR;
	ptr = v;
	return *this;
}

RValue& RValue::operator=(bool v)
{
	__localFree();
	kind = VALUE_REAL;
	val = v ? 1.0 : 0.0;
	return *this;
}

RValue& RValue::operator=(const char* v)
{
	__localFree();
	YYCreateString(this, v);
	return *this;
}

RValue& RValue::operator=(std::string v)
{
	return operator=(v.c_str());
}

RValue& RValue::operator=(std::wstring v)
{
	flags = 0;
	int __size = WideCharToMultiByte(CP_UTF8, 0, v.c_str(), -1, nullptr, 0, nullptr, nullptr);
	LPSTR s = new CHAR[__size];

	WideCharToMultiByte(CP_UTF8, 0, v.c_str(), -1, s, __size, nullptr, nullptr);
	RValue& ret(operator=(s));
	delete[] s;
	s = nullptr;

	return ret;
}

RValue& RValue::operator++()
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_BOOL:
		case VALUE_REAL: ++val; break;
		case VALUE_INT32: ++v32; break;
		case VALUE_INT64: ++v64; break;
		case VALUE_PTR: ptr = reinterpret_cast<void*>(reinterpret_cast<char*>(ptr) + 1); break;
		default: abort();
	}
	return *this;
}

RValue RValue::operator++(int)
{
	RValue tmp(*this);
	operator++();
	return tmp;
}

RValue& RValue::operator--()
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_BOOL:
		case VALUE_REAL: --val; break;
		case VALUE_INT32: --v32; break;
		case VALUE_INT64: --v64; break;
		case VALUE_PTR: ptr = reinterpret_cast<void*>(reinterpret_cast<char*>(ptr) - 1); break;
		default: abort();
	}
	return *this;
}

RValue RValue::operator--(int)
{
	RValue tmp(*this);
	operator--();
	return tmp;
}

RValue& RValue::operator+=(const char* v)
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_STRING:
		{
			// if string then concatenate, if not then convert to string
			const char* pFirst = (pRefString != nullptr) ? pRefString->get() : nullptr;
			char* pNew = YYAddString(pFirst, v);
			YYCreateString(this, pNew);
			YYFree(pNew);
			break;
		} // end block
		default: abort();
	}

	return *this;
}

bool RValue::operator==(const RValue& rhs) const
{
	int lhsType = kind & MASK_KIND_RVALUE;
	int rhsType = rhs.kind & MASK_KIND_RVALUE;

	if (lhsType == VALUE_STRING && rhsType == VALUE_STRING)
		return strcmp(pRefString->get(), rhs.pRefString->get()) == 0;

	double lhsD = this->asReal();
	double rhsD = 0.0;
	switch (rhsType)
	{
		case VALUE_REAL:
		case VALUE_BOOL: rhsD = rhs.val; break;
		case VALUE_INT32: rhsD = static_cast<double>(rhs.v32); break;
		case VALUE_INT64: rhsD = static_cast<double>(rhs.v64); break;
		case VALUE_PTR: rhsD = static_cast<double>(reinterpret_cast<uintptr_t>(ptr)); break;
		case VALUE_UNSET:
		case VALUE_UNDEFINED: rhsD = std::nan(""); break;
		default: abort(); break;
	}

	return lhsD == rhsD;
}

bool RValue::operator!=(const RValue& rhs) const
{
	return (!(operator==(rhs)));
}

const RValue& RValue::DoArrayIndex(const int _index)
{
	const RValue* pV = nullptr;
	if ((kind & MASK_KIND_RVALUE) == VALUE_ARRAY && (pRefArray != nullptr)) {
		ldiv_t ind = ldiv(_index, VARIABLE_ARRAY_MAX_DIMENSION);
		if (pRefArray->pOwner == nullptr) {
			pRefArray->pOwner = this;
		}

		const DynamicArrayOfRValue* pArr = nullptr;
		if ((ind.quot >= 0) && (pRefArray != nullptr) && (ind.quot < pRefArray->length)) {
			pArr = &pRefArray->pArray[ind.quot];
			if ((ind.rem >= 0) && (ind.rem < pArr->length)) {
				pV = &pArr->arr[ind.rem];
			}
			else {
				abort();
			}
		}
		else {
			abort();
		}
	}
	else {
		pV = this;
		abort();
	}

	return *pV;
}

const RValue& RValue::operator[](const int _index)
{
	return DoArrayIndex(_index);
}

RValue& RValue::operator()(const int _index)
{
	return *ARRAY_LVAL_RValue(this, _index);
}

std::string RValue::asString() const
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_REAL: return std::to_string(val);
		case VALUE_INT32: return std::to_string(v32);
		case VALUE_INT64: return std::to_string(v64);
		case VALUE_PTR: {
			char buf[32] = { '\0' };
			memset(buf, 0, sizeof(buf));
			std::snprintf(buf, sizeof(buf), "%p", ptr);
			return std::string(buf);
		}
		case VALUE_ARRAY: {
			// WARNING: A VERY VERY VERY HORRIBLE IMPLEMENTATION!!

			if (this->pRefArray->pArray == nullptr)
				return "{ <empty array pointer> }";
			int arrlen = this->pRefArray->pArray->length;
			if (arrlen <= 0) return "{ <empty array> }";
			/*
			std::stringstream ss;

			ss << "{ ";
			for (int i = 0; i < arrlen; i++)
			{
				const RValue& elem = this->DoArrayIndex(i);
				// "i":
				ss << '"' << i << "\": ";
				if ((elem.kind & MASK_KIND_RVALUE) == VALUE_STRING) ss << '"';
				ss << elem.asString();
				if ((elem.kind & MASK_KIND_RVALUE) == VALUE_STRING) ss << '"';
				if (i < arrlen - 1) ss << ", ";
			}
			ss << " }";

			return ss.str();
			*/
			return nullptr;
		}
		case VALUE_BOOL: return (val > 0.5) ? "true" : "false";
		case VALUE_UNSET: return "<unset>"; // ??????????
		case VALUE_UNDEFINED: return "<undefined>";
		case VALUE_STRING: return pRefString->get();
		default: abort();
	}
}

double RValue::asReal() const
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_REAL:
		case VALUE_BOOL:  return val;
		case VALUE_UNDEFINED:
		case VALUE_UNSET: return std::nan("");
		case VALUE_INT32: return static_cast<double>(v32);
		case VALUE_INT64: return static_cast<double>(v64);
		case VALUE_PTR:   return static_cast<double>(reinterpret_cast<uintptr_t>(ptr));
		case VALUE_STRING: {
			try {
				return std::stod(pRefString->get());
			}
			catch (...) {
				return std::nan("");
			}
		}
		default: abort();
	}
}

int RValue::asInt32() const
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_REAL:
		case VALUE_BOOL: return static_cast<int>(std::floor(val));
		case VALUE_INT32: return v32;
		case VALUE_INT64: return static_cast<int>(v64);
		case VALUE_PTR: return static_cast<int>(reinterpret_cast<intptr_t>(ptr));
		case VALUE_STRING: {
			try {
				return std::stoi(pRefString->get());
			}
			catch (...) {
				abort();
			}
		}
		default: abort();
	}
}

bool RValue::asBoolean() const
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_REAL:
		case VALUE_BOOL: return val > 0.5 ? true : false;
		case VALUE_INT32: return v32 > 0 ? true : false;
		case VALUE_INT64: return v64 > 0L ? true : false;
		case VALUE_PTR: return ptr != nullptr ? true : false;
		case VALUE_STRING: {
			try {
				const std::string v = pRefString->get();
				if (v == "true" || v == "True")
					return true;
				else if (v == "false" || v == "False")
					return false;
				abort();
			}
			catch (...) {
				abort();
			}
		}
		default: abort();
	}
}

long long RValue::asInt64() const
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_REAL:
		case VALUE_BOOL: return static_cast<long long>(std::floor(val));
		case VALUE_INT32: return static_cast<long long>(v32);
		case VALUE_INT64: return v64;
		case VALUE_PTR: return static_cast<long long>(reinterpret_cast<uintptr_t>(ptr));
		case VALUE_STRING: {
			try {
				return std::stoll(pRefString->get());
			}
			catch (...) {
				abort();
			}
		}
		default: abort();
	}
}

bool RValue::isNumber() const
{
	int mKind = kind & MASK_KIND_RVALUE;
	return (mKind == VALUE_REAL || mKind == VALUE_INT32 || mKind == VALUE_INT64 || mKind == VALUE_BOOL);
}

bool RValue::isUnset() const
{
	return kind == VALUE_UNSET;
}

RValue::operator bool() const
{
	return asBoolean();
}

RValue::operator long long() const
{
	return asInt64();
}

RValue::operator int() const
{
	return asInt32();
}

RValue::operator double() const
{
	return asReal();
}

RValue::operator std::string()
{
	return asString();
}

void* RValue::asPointer() const
{
	switch (kind & MASK_KIND_RVALUE)
	{
		case VALUE_REAL:
		case VALUE_BOOL: return reinterpret_cast<void*>(static_cast<uintptr_t>(std::floor(val)));
		case VALUE_INT32: return reinterpret_cast<void*>(static_cast<uintptr_t>(v32));
		case VALUE_INT64: return reinterpret_cast<void*>(static_cast<uintptr_t>(v64));
		case VALUE_PTR: return ptr;
		default: abort();
	}
}

RValue::operator void*() const
{
	return asPointer();
}

const DynamicArrayOfRValue* RValue::asArray() const
{
	if ((kind & MASK_KIND_RVALUE) == VALUE_ARRAY)
		return pRefArray->pArray;
	else
		abort();
}