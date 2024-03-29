# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator-\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Returns the difference between two big-integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Word> operator-() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator-(const xieite::math::BigInteger<Word>& minuend, const xieite::math::BigInteger<Word>& subtrahend) noexcept;
```
#### 3)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr xieite::math::BigInteger<Word> operator-(const xieite::math::BigInteger<Word>& minuend, Integer subtrahend) noexcept;
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
