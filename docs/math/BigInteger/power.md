# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:power
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Raises a `xieite::math::BigInteger` to an exponent.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger power(xieite::math::BigInteger exponent) const;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger power(Integer exponent) const;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 2;

    std::cout << bigInteger.power(3).string() << '\n';
}
```
Output:
```
8
```
