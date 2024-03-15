# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator*=\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Assigns the product of this big-integer with another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::BigInteger<Word>& operator*=(const xieite::math::BigInteger<Word>& multiplicand) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::BigInteger<Word>& operator*=(Integer multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    xieite::math::BigInteger bigInteger = 9;

    bigInteger *= 3;

    std::println("{}", bigInteger.string());
}
```
Output:
```
27
```
