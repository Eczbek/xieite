# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:string
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Converts a `xieite::math::BigInteger` to a `std::string`.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string string(std::make_signed_t<std::size_t> radix = 10, const xieite::math::IntegerStringComponents& components = xieite::math::IntegerStringComponents()) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    std::cout << xieite::math::BigInteger(418).string() << '\n';
}
```
Output:
```
418
```
