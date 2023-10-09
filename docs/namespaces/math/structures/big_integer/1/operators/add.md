# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../../big_integer.md)\:\:operator+
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Datum> operator+() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator+(const xieite::math::BigInteger<Datum>& augend, const xieite::math::BigInteger<Datum>& addend) noexcept;
```
#### 3)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator+(const xieite::math::BigInteger<Datum>& augend, const Integer addend) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) + 3).string() << '\n';
}
```
Output:
```
12
```
