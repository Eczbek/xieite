# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb_>](../../../../big_integer.md)\:\:operator++\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Increments a big-integer.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Limb_>& operator++() noexcept;
```
#### 2)
```cpp
constexpr xieite::math::BigInteger<Limb_>& operator++(int) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigIntegral = 7;

    std::println("{}", (++bigIntegral).string());
}
```
Output:
```
8
```
