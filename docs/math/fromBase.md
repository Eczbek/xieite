# [xieite](../xieite.md)\:\:[math](../math.md)\:\:fromBase
Defined in header [<xieite/math/fromBase.hpp>](../../include/xieite/math/fromBase.hpp)

&nbsp;

## Description
Converts an integer string to base-10

&nbsp;

## Synopsis
```cpp
template<std::integral Integer = int>
[[nodiscard]]
constexpr Integer fromBase(std::size_t base, std::string_view value, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`. Set to `int` by default
#### Function parameters
- `base` - A `std::size_t`, the current base of value
- `value` - A `std::string_view`, the value to convert to base-10
- `digits` - A `std:string_view`, the digits to use, set to `"0123456789abcdefghijklmnopqrstuvwxyz"` by default
#### Return type
- `Integer`, equal to `value` in base-10

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/fromBase.hpp>

int main() {
    std::cout << xieite::math::fromBase(21, "g4h3") << '\n';
}
```
Output:
```
150300
```
