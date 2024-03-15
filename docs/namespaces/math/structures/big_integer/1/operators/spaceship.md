# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator<=>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Compares two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word>& leftComparand, const xieite::math::BigInteger<Word>& rightComparand) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word>& leftComparand, Integer rightComparand) noexcept;
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
