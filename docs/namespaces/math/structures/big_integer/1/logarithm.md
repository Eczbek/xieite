# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../big_integer.md)\:\:logarithm\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes the logarithm of a `xieite::math::BigInteger<Limb>` to a base. Taking the logarithm of a negative value invokes undefined behavior, as does using a unary or negative base.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> logarithm(const xieite::math::BigInteger<Limb>& base) const noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> logarithm(Integral base) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 1000;

    std::println("{}", bigIntegral.logarithm(10).string());
}
```
Output:
```
3
```
