# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator==\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Compares two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Limb>& leftComparand, const xieite::math::BigInteger<Limb>& rightComparand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Limb>& leftComparand, Integral rightComparand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger foo = 16;
    xieite::math::BigInteger bar = 4;

    std::println("{}", foo == bar.power(2));
}
```
Output:
```
true
```
