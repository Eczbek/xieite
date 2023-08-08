# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:string
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Converts a `xieite::math::BigInteger` to a `std::string`

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr std::string string() const noexcept;
```
#### Return type
- `std::string`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << xieite::math::BigInteger(418).string() << '\n';
}
```
Output:
```
418
```
