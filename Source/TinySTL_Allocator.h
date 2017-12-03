#pragma once
#include <cstddef>
#include <climits>

namespace TinySTL
{

  template <typename T>
  class Allocator
  {
  public:
    using ValueType           = T;
    using Pointer             = T*;
    using ConstPointer        = const T*;
    using Reference           = T&;
    using ConstReference      = const T&;
    using RightReference      = T&&;
    using ConstRightReference = const T&&;
    using SizeType            = std::size_t;
    using DifferenceType      = std::ptrdiff_t;

    template <typename U>
    struct Rebind { using Other = Allocator<U>; };

    Pointer Address(Reference ref) { return static_cast<Pointer>(&ref); }

    ConstPointer ConstAddress(ConstReference kRef) { return static_cast<ConstPointer>(&kRef); }

    constexpr SizeType MaxSize() const { return static_cast<SizeType>(UINT_MAX / sizeof(T)); }
  };

} // end of namespace TinySTL