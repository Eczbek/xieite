# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:root\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes any root of a `xieite::math::BigInteger<Word>`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::expected<xieite::math::BigInteger<Word>, xieite::errors::Type> root(const xieite::math::BigInteger<Word>& degree) const noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr std::expected<xieite::math::BigInteger<Word>, xieite::errors::Type> root(Integral degree) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 8;

    std::println("{}", bigIntegral.root(3).value().string());
}
```
Output:
```
2
```
