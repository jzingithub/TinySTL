#pragma once

namespace TinySTL
{

  template <typename T, T Val>
  struct IntegralConstant
  {
    static constexpr T val  = Val;
    using ValueType         = T;
    using Type              = IntegralConstant<T, Val>;

    constexpr operator ValueType() const noexcept { return val; }
    constexpr ValueType()() const noexcept { return val; }
  };

  using TrueType  = IntegralConstant<bool, true>;
  using FalseType = IntegralConstant<bool, false>;

  // determine whether the type 'T' has a trivial destructor
  template <typename T>
  struct TypeTraits
  {
    TrueType HasTrivialDestructor; // to do
  };

  template <typename Iterator>
  inline T::Pointer ValueType(Iterator iter) { return &(*iter); }

}