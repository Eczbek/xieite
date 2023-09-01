# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger<Datum, Operand>](../BigInteger.md)\:\:operator=
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Datum, Operand>& operator=(const xieite::math::BigInteger<Datum, Operand>& value) const noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Datum, Operand>& operator=(Integer value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    xieite::math::BigInteger<Datum, Operand> bigInteger = 17;

    bigInteger = 41;

    std::cout << bigInteger.string() << '\n';
}
```
Output:
```
41
```
