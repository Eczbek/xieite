# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:logarithm\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes the logarithm of a `xieite::math::BigInteger<Word>` to a base.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Word> logarithm(const xieite::math::BigInteger<Word>& base) const;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr xieite::math::BigInteger<Word> logarithm(Integer base) const;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigInteger = 1000;

    std::println("{}", bigInteger.logarithm(10).string());
}
```
Output:
```
3
```
