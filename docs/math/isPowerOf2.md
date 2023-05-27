# [xieite](../../README.md)::[math](../math.md)::isPowerOf2
Defined in header [<xieite/math/isPowerOf2.hpp>](../../include/xieite/math/isPowerOf2.hpp)

<br/>

Checks that a value is a power of 2

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr bool isPowerOf2(std::unsigned_integral auto value) noexcept;
```
### Parameters
- `value` - An `auto` copy, satisfying `std::unsigned_integral`
### Return value
- A `bool`, whether or not value is a power of 2

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/isPowerOf2.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::math::isPowerOf2(4)
		<< '\n'
		<< xieite::math::isPowerOf2(0)
		<< '\n';
}
```
Output:
```
true
false
```
