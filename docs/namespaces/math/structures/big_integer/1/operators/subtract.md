# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../../big_integer.md)\:\:operator-\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Returns the difference between two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Limb> operator-() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator-(const xieite::math::BigInteger<Limb>& minuend, const xieite::math::BigInteger<Limb>& subtrahend) noexcept;
```
#### 3)
```cpp
template<std::integral Integral>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator-(const xieite::math::BigInteger<Limb>& minuend, Integral subtrahend) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", (xieite::math::BigInteger(9) - 3).string());
}
```
Output:
```
6
```
