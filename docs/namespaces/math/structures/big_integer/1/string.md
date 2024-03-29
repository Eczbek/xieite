# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:string\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Converts a `xieite::math::BigInteger<Word>` to a `std::string`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::string string(xieite::math::SignedSize radix = 10, const xieite::strings::IntegerComponents& components = xieite::strings::IntegerComponents()) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", xieite::math::BigInteger(418).string());
}
```
Output:
```
418
```
