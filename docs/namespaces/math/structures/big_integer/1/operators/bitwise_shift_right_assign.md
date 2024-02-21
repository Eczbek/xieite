# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator>>=
Defined in header [<xieite/math/big_integer.hpp"](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
constexpr xieite::math::BigInteger<Word>& operator>>=(const xieite::math::BigInteger<Word>& positions) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Word>& operator>>=(Integer positions) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger<Word> bigInteger = 9;

    bigInteger >>= 3;

    std::cout << bigInteger.string() << '\n';
}
```
Output:
```
1
```
