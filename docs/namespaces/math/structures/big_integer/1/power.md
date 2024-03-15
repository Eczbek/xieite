# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:power\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Raises a `xieite::math::BigInteger<Word>` to an exponent.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Word> power(const xieite::math::BigInteger<Word>& exponent) const;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr xieite::math::BigInteger<Word> power(Integer exponent) const;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigInteger = 2;

    std::println("{}", bigInteger.power(3).string());
}
```
Output:
```
8
```
