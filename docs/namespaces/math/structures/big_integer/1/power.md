# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:power\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Raises a `xieite::math::BigInteger<Word>` to an exponent.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::expected<xieite::math::BigInteger<Word>, xieite::errors::Type> power(const xieite::math::BigInteger<Word>& exponent) const noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr std::expected<xieite::math::BigInteger<Word>, xieite::errors::Type> power(Integral exponent) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 2;

    std::println("{}", bigIntegral.power(3).value().string());
}
```
Output:
```
8
```
