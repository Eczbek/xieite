# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:Type
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
An alias to the `Word` template parameter.

&nbsp;

## Synopsis
#### 1)
```cpp
using Type = Word;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <cstdint>
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    using Word = std::uint64_t;

    std::println("{}", std::same_as<Word, xieite::math::BigInteger<Word>::Type>);
}
```
Output:
```
true
```
