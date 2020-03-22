#ifndef _STDDEF_H_
#define _STDDEF_H_

#undef NULL
#define NULL 0

#undef offsetof
#define offsetof(type, member) __builtin_offsetof(type, member)

typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __WCHAR_TYPE__ wchar_t;
typedef __SIZE_TYPE__ size_t;

#endif
