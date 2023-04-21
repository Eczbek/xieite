# `xieite::math::fromBase`
Defined in header [`<xieite/math/fromBase.hpp>`](../../include/xieite/math/fromBase.hpp)

<br/>

Converts an integer string to base 10.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral = int>
[[nodiscard]]
constexpr Integral fromBase(std::string_view value, std::size_t base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`. Set to `int` by default
### Parameters
- `value` - A `std::string_view` copy, the value to convert to base 10
- `base` - A `std::size_t` copy, the current base of `value`
- `digits` - A `std:string_view` copy, the digits to use, set to `"0123456789abcdefghijklmnopqrstuvwxyz"` by default
### Return value
- An `Integral`, equal to `value` in base 10

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/fromBase.hpp>

int main() {
	std::cout << xieite::math::fromBase("g4h3", 21) << '\n';
}
```
Output:
```
150300
```
