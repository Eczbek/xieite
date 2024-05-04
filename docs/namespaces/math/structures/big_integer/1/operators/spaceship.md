# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word_>](../../../../big_integer.md)\:\:operator\<=\>\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Compares two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word_>& leftComparand, const xieite::math::BigInteger<Word_>& rightComparand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word_>& leftComparand, Integral_ rightComparand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", xieite::math::BigInteger(9) > 3);
}
```
Output:
```
true
```
