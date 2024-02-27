# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsBigInteger
Defined in header [<xieite/traits/is_big_integer.hpp>](../../../include/xieite/traits/is_big_integer.hpp)

&nbsp;

Forward-declares `xieite::math::BigInteger` and does stuff.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
struct IsIntegerlike
: std::false_type {};
```
#### 2)
```cpp
template<std::unsigned_integral Word>
struct IsIntegerlike<xieite::math::BigInteger<Word>>
: std::true_type {};
```
