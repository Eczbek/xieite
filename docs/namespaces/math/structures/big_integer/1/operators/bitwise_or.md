# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word_>](../../../../big_integer.md)\:\:operator|\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Returns the bitwise OR result of two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator|(const xieite::math::BigInteger<Word_>& leftOperand, const xieite::math::BigInteger<Word_>& rightOperand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator|(const xieite::math::BigInteger<Word_>& leftOperand, Integral_ rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", (xieite::math::BigInteger(9) | 3).string());
}
```
Output:
```
11
```
