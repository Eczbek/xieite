# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator%=\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Assigns the remainder after division of this big-integer with another. Taking the remainder after division by zero invokes undefined behavior.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Limb>& operator%=(const xieite::math::BigInteger<Limb>& divisor);
```
#### 2)
```cpp
template<std::integral Integral>
constexpr xieite::math::BigInteger<Limb>& operator%=(Integral divisor);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 9;

    bigIntegral %= 3;

    std::println("{}", bigIntegral.string());
}
```
Output:
```
0
```
