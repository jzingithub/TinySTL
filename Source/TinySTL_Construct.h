// author: jz
// The new and delete operator in C++ is responsible for both
// memory allocation (deallocation) and element construction (destruction).
// For more fine-grained control, separate these two operation 
#pragma once
#include <new>
#include "TinySTL_TypeTraits.h"

namespace TinySTL
{

  template <typename T1, typename T2>
  inline void Construct(T1 *ptr, const T2 &val)
  {
    new (ptr) T1(val); // placement new
  }

  // if the value type pointed by 'ForwardIterator' has trivial destructor, do nothing
  template <typename ForwardIterator>
  inline void _DestroyAux(ForwardIterator first, ForwardIterator last, TinySTL::TrueType) { }

  // if the value type pointed by 'ForwardIterator' has non-trivial destructor
  template <typename ForwardIterator>
  inline void _DestroyAux(ForwardIterator first, ForwardIterator last, TinySTL::FalseType)
  {
    for (; first < last; ++first) { Destroy(&(*first)); }
  }

  // note that the third argument is not used
  template <typename ForwardIterator, typename T>
  inline void _Destroy(ForwardIterator first, ForwardIterator last, T*)
  {
    using HasTrivialDestructor = typename TypeTraits<T>::HasTrivialDestructor;
    _DestroyAux(first, last, HasTrivialDestructor());
  }

  template <typename T> inline void Destroy(T *ptr) { ptr->~T(); }

  template <typename ForwardIterator>
  inline void Destroy(ForwardIterator first, ForwardIterator last)
  {
    _Destroy(first, last, ValueType(first)); // ValueType(T): to do
  }

  // specialization version for char* and wchar_t*
  inline void Destroy(char*, char*) { /* do nothing */ }
  inline void Destroy(wchar_t*, wchar_t*) { /* do nothing */ }

} // end of namespace TinySTL