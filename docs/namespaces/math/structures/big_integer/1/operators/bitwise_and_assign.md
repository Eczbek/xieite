# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word_>](../../../../big_integer.md)\:\:operator&=\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Assigns the bitwise AND result of this big-integer with another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Word_>& operator&=(const xieite::math::BigInteger<Word_>& operand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_>
constexpr xieite::math::BigInteger<Word_>& operator&=(Integral_ operand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 9;

    bigIntegral &= 3;

    std::println("{}", bigIntegral.string());
}
```
Output:
```
1
```
