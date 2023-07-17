# [xieite](../xieite.md)::[math](../math.md)::digits
Defined in header [<xieite/math/digits.hpp>](../../include/xieite/math/digits.hpp)

<br/>

Calculates the number of digits in a value of any base

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::unsigned_integral UnsignedIntegral>
[[nodiscard]]
constexpr std::size_t digits(const UnsignedIntegral value, const std::size_t base = 10) noexcept;
```
### Template parameters
- `Integral` - A type satisfying `std::integral`
### Parameters
- `value` - An `Integral` copy
- `base` - An `Integral` copy, set to `10` by default
### Return value
- An `Integral`, the number of digits

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
