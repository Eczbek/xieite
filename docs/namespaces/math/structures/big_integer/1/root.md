# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../big_integer.md)\:\:root\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes any root of a `xieite::math::BigInteger<Limb>`. Taking the root of a negative value invokes undefined behavior.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> root(const xieite::math::BigInteger<Limb>& degree) const noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> root(Integral degree) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 8;

    std::println("{}", bigIntegral.root(3).string());
}
```
Output:
```
2
```
