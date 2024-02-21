# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:absolute
Defined in header [<xieite/math/big_integer.hpp"](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Gets the absolute value of a `xieite::math::BigInteger`.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::BigInteger<Word> absolute() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger<Word> bigInteger = -999;

    std::cout << bigInteger.absolute().string() << '\n';
}
```
Output:
```
999
```
