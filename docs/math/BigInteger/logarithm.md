# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:logarithm
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Calculates the logarithm of a `xieite::math::BigInteger` to a base.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr xieite::math::BigInteger logarithm(const xieite::math::BigInteger& base) const;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr xieite::math::BigInteger logarithm(Integer base) const;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger bigInteger = 1000;

    std::cout << bigInteger.logarithm(10).string() << '\n';
}
```
Output:
```
3
```
