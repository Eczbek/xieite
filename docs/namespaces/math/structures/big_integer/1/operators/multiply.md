# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator*\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Returns the product of two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator*(const xieite::math::BigInteger<Word>& multiplier, const xieite::math::BigInteger<Word>& multiplicand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator*(const xieite::math::BigInteger<Word>& multiplier, Integral multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", (xieite::math::BigInteger(9) * 3).string());
}
```
Output:
```
27
```
