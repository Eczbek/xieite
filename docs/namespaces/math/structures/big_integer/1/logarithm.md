# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb_>](../../../big_integer.md)\:\:logarithm\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes the logarithm of a `xieite::math::BigInteger<Limb_>` to a base.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> logarithm(const xieite::math::BigInteger<Limb_>& base) const noexcept;
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> logarithm(Integral_ base) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 1000;

    std::println("{}", bigIntegral.logarithm(10).value().string());
}
```
Output:
```
3
```
