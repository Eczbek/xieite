# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:root
Defined in header [<xieite/math/big_integer.hpp"](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Computes any root of a `xieite::math::BigInteger`.

&nbsp;

## Synopses
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
#include <iostream>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger<Word> bigInteger = 8;

    std::cout << bigInteger.root(3).string() << '\n';
}
```
Output:
```
2
```
