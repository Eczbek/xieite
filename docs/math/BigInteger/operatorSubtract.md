# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger<Datum>](../BigInteger.md)\:\:operator-
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Datum> operator-() const noexcept;
```
#### 2)
```cpp
friend constexpr xieite::math::BigInteger<Datum> operator-(const xieite::math::BigInteger<Datum>& minuend, const xieite::math::BigInteger<Datum>& subtrahend) noexcept;
```
#### 3)
```cpp
template<std::integral Integer>
friend constexpr xieite::math::BigInteger<Datum> operator-(const xieite::math::BigInteger<Datum>& minuend, const Integer subtrahend) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) - 3).string() << '\n';
}
```
Output:
```
6
```
