# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger<Datum, Operand>](../BigInteger.md)\:\:operator--
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Datum, Operand>& operator--() noexcept;
```
#### 2)
```cpp
constexpr xieite::math::BigInteger<Datum, Operand>& operator--(int) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger<Datum, Operand> bigInteger = 7;

    std::cout << (--bigInteger).string() << '\n';
}
```
Output:
```
6
```
