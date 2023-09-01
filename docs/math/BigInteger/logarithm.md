# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger<Datum, Operand>](../BigInteger.md)\:\:logarithm
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Calculates the logarithm of a `xieite::math::BigInteger` to a base.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Datum, Operand> logarithm(const xieite::math::BigInteger<Datum, Operand>& base) const;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Datum, Operand> logarithm(Integer base) const;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger<Datum, Operand> bigInteger = 1000;

    std::cout << bigInteger.logarithm(10).string() << '\n';
}
```
Output:
```
3
```
