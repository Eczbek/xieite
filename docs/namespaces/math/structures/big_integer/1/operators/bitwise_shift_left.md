# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb_>](../../../../big_integer.md)\:\:operator\<\<\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Returns this big-integer bitwise shifted to the left.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator<<(const xieite::math::BigInteger<Limb_>& leftOperand, const xieite::math::BigInteger<Limb_>& rightOperand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator<<(const xieite::math::BigInteger<Limb_>& leftOperand, Integral_ rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", (xieite::math::BigInteger(9) << 3).string());
}
```
Output:
```
72
```
