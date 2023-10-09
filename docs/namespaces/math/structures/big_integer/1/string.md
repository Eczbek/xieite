# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../big_integer.md)\:\:string
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Converts a `xieite::math::BigInteger` to a `std::string`.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::string string(int radix = 10, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", char negativeSign = '-', bool caseSensitive = false) const noexcept;
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
