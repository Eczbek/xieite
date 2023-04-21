# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::toBase`
Defined in header [`<xieite/math/toBase.hpp>`](../../include/xieite/math/toBase.hpp)

<br/>

Converts an integer to a string in any base. Doubles as a compile-time method of stringifying integers.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral = int>
[[nodiscard]]
constexpr std::string toBase(Integral value, std::size_t base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`. Set to `int` by default
### Parameters
- `value` - An `Integral` copy
- `base` - A `std::size_t` copy, the desired base
- `digits` - A `std::string_view` copy, the digits to use in the result. Set to `"0123456789abcdefghijklmnopqrstuvwxyz"` by default
### Return value
- A `std::string`, equal to `value` in the `base` base

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/toBase.hpp>

int main() {
	std::cout << xieite::math::toBase(12, 2) << '\n';
}
```
Output:
```
1100
```
