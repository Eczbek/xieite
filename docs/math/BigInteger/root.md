# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger<Datum, Operand>](../BigInteger.md)\:\:root
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Calculates any root of a `xieite::math::BigInteger`.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Datum, Operand> root(const xieite::math::BigInteger<Datum, Operand>& degree) const;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Datum, Operand> root(Integer degree) const;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger<Datum, Operand> bigInteger = 8;

    std::cout << bigInteger.root(3).string() << '\n';
}
```
Output:
```
2
```
