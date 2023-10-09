# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../../big_integer.md)\:\:operator*
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator*(const xieite::math::BigInteger<Datum>& multiplier, const xieite::math::BigInteger<Datum>& multiplicand) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator*(const xieite::math::BigInteger<Datum>& multiplier, const Integer multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) * 3).string() << '\n';
}
```
Output:
```
27
```
