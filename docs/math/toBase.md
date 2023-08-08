# [xieite](../xieite.md)\:\:[math](../math.md)\:\:toBase
Defined in header [<xieite/math/toBase.hpp>](../../include/xieite/math/toBase.hpp)

&nbsp;

## Description
Converts an integer to a string in any base. Doubles as a compile-time method of stringifying integers

&nbsp;

## Synopsis
```cpp
template<std::integral Integer = int>
[[nodiscard]]
constexpr std::string toBase(std::size_t base, Integer value, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz");
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`. Set to `int` by default
#### Function parameters
- `base` - A `std::size_t`, the desired base
- `value` - An `Integer`
- `digits` - A `std::string_view`, the digits to use in the result. Set to `"0123456789abcdefghijklmnopqrstuvwxyz"` by default
#### Return type
- `std::string`, equal to value in the base base

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/toBase.hpp>

int main() {
    std::cout << xieite::math::toBase(2, 13) << '\n';
}
```
Output:
```
1101
```
