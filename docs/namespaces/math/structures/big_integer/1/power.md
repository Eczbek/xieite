# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:power
Defined in header [<xieite/math/big_integer.hpp"](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Raises a `xieite::math::BigInteger` to an exponent.

&nbsp;

## Synopses
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
#include <iostream>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger<Word> bigInteger = 2;

    std::cout << bigInteger.power(3).string() << '\n';
}
```
Output:
```
8
```
