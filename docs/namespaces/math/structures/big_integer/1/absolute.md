# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:absolute\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Gets the absolute value of a `xieite::math::BigInteger<Word>`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Word> absolute() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigInteger = -999;

    std::println("{}", bigInteger.absolute().string());
}
```
Output:
```
999
```
