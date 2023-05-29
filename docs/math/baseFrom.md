# [xieite](../../README.md)::[math](../math.md)::baseFrom
Defined in header [<xieite/math/baseFrom.hpp>](../../include/xieite/math/baseFrom.hpp)

<br/>

Converts an integer string to base-10

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral = int>
[[nodiscard]]
constexpr Integral baseFrom(std::size_t base, std::string_view value, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`. Set to `int` by default
### Parameters
- `base` - A `std::size_t` copy, the current base of value
- `value` - A `std::string_view` copy, the value to convert to base-10
- `digits` - A `std:string_view` copy, the digits to use, set to `"0123456789abcdefghijklmnopqrstuvwxyz"` by default
### Return value
- An `Integral`, equal to `value` in base-10

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/baseFrom.hpp>

int main() {
	std::cout << xieite::math::baseFrom(21, "g4h3") << '\n';
}
```
Output:
```
150300
```
