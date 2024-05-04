# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word_>](../../../../big_integer.md)\:\:operator==\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Compares two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Word_>& leftComparand, const xieite::math::BigInteger<Word_>& rightComparand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Word_>& leftComparand, Integral_ rightComparand) noexcept;
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
