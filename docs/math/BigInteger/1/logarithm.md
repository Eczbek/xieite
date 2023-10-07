# [xieite](../../../xieite.md)\:\:[math](../../../math.md)\:\:[BigInteger<Datum>](../../BigInteger.md)\:\:logarithm
Defined in header [<xieite/math/BigInteger.hpp>](../../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Computes the logarithm of a `xieite::math::BigInteger` to a base.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Datum> logarithm(const xieite::math::BigInteger<Datum>& base) const;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr xieite::math::BigInteger<Datum> logarithm(Integer base) const;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger<Datum> bigInteger = 1000;

    std::cout << bigInteger.logarithm(10).string() << '\n';
}
```
Output:
```
3
```
