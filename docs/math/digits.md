# [xieite](../xieite.md)::[math](../math.md)::digits
Defined in header [<xieite/math/digits.hpp>](../../include/xieite/math/digits.hpp)

<br/>

Calculates the number of digits in a value of any base

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::size_t digits(const std::integral auto value, const std::size_t base = 10) noexcept;
```
### Parameters
- `value` - A value of any type satisfying `std::integral`
- `base` - An `Integral`, set to `10` by default
### Return value
- A `std::size_t`, the number of digits

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/digits.hpp>

int main() {
	std::cout
		<< xieite::math::digits(12) << '\n'
		<< xieite::math::digits(0b110110, 2) << '\n';
}
```
Output:
```
2
6
```
