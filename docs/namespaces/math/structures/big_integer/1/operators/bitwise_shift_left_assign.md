# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator\<\<=\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Assigns this big-integer to itself bitwise shifted to the left.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Limb>& operator<<=(const xieite::math::BigInteger<Limb>& positions) noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
constexpr xieite::math::BigInteger<Limb>& operator<<=(Integral positions) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 9;

    bigIntegral <<= 3;

    std::println("{}", bigIntegral.string());
}
```
Output:
```
72
```
