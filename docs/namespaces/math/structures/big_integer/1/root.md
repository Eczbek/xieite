# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:root\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes any root of a `xieite::math::BigInteger<Word>`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Word> root(const xieite::math::BigInteger<Word>& degree) const;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr xieite::math::BigInteger<Word> root(Integer degree) const;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigInteger = 8;

    std::println("{}", bigInteger.root(3).string());
}
```
Output:
```
2
```
