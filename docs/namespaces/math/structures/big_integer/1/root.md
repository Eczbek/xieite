# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb_>](../../../big_integer.md)\:\:root\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes any root of a `xieite::math::BigInteger<Limb_>`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> root(const xieite::math::BigInteger<Limb_>& degree) const noexcept;
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> root(Integral_ degree) const noexcept;
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
