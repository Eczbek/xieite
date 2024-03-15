# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator=\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Assigns this big-integer to another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Word>& operator=(const xieite::math::BigInteger<Word>& value) const noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Word>& operator=(Integer value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigInteger = 17;

    bigInteger = 41;

    std::println("{}", bigInteger.string());
}
```
Output:
```
41
```
