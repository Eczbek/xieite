# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator<<=\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Assigns this big-integer to itself bitwise shifted to the left.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Word>& operator<<=(const xieite::math::BigInteger<Word>& positions) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Word>& operator<<=(Integer positions) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigInteger = 9;

    bigInteger <<= 3;

    std::println("{}", bigInteger.string());
}
```
Output:
```
72
```
