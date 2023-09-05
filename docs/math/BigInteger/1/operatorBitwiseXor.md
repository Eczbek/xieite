# [xieite](../../../xieite.md)\:\:[math](../../../math.md)\:\:[BigInteger<Datum>](../../BigInteger.md)\:\:operator^
Defined in header [<xieite/math/BigInteger.hpp>](../../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr xieite::math::BigInteger<Datum> operator^(const xieite::math::BigInteger<Datum>& leftOperand, const xieite::math::BigInteger<Datum>& rightOperand) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
friend constexpr xieite::math::BigInteger<Datum> operator^(const xieite::math::BigInteger<Datum>& leftOperand, const Integer rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << (xieite::math::BigInteger(9) ^ 3).string() << '\n';
}
```
Output:
```
10
```
