# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator%\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Returns the remainder after division of two big-integers. Taking the remainder after division by zero invokes undefined behavior.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator%(const xieite::math::BigInteger<Limb>& dividend, const xieite::math::BigInteger<Limb>& divisor);
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator%(const xieite::math::BigInteger<Limb>& dividend, Integral divisor);
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
