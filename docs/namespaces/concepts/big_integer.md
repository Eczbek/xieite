# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:BigInteger
Defined in header [<xieite/concepts/big_integer.hpp>](../../../include/xieite/concepts/big_integer.hpp)

&nbsp;

## Description
Specifies that a type is a specialization of `xieite::math::BigInteger`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept BigInteger = xieite::traits::IsBigInteger<Type>::value;
```
