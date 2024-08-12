# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb_>](../../../../big_integer.md)\:\:operator%\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Returns the remainder after division of two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator%(const xieite::math::BigInteger<Limb_>& dividend, const xieite::math::BigInteger<Limb_>& divisor);
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator%(const xieite::math::BigInteger<Limb_>& dividend, Integral_ divisor);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", (xieite::math::BigInteger(9) % 3).string());
}
```
Output:
```
0
```
