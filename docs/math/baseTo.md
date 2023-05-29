# [xieite](../../README.md)::[math](../math.md)::baseTo
Defined in header [<xieite/math/baseTo.hpp>](../../include/xieite/math/baseTo.hpp)

<br/>

Converts an integer to a string in any base. Doubles as a compile-time method of stringifying integers

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral = int>
[[nodiscard]]
constexpr std::string baseTo(std::size_t base, Integral value, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz");
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`. Set to `int` by default
### Parameters
- `base` - A `std::size_t` copy, the desired base
- `value` - An `Integral` copy
- `digits` - A `std::string_view` copy, the digits to use in the result. Set to `"0123456789abcdefghijklmnopqrstuvwxyz"` by default
### Return value
- A `std::string`, equal to value in the base base

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/baseTo.hpp>

int main() {
	std::cout << xieite::math::baseTo(2, 13) << '\n';
}
```
Output:
```
1101
```
