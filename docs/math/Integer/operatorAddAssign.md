# [xieite](../../../README.md)::[math](../../math.md)::[Integer<bits, sign>](../Integer.md)::operator+=
Defined in header [<xieite/math/Integer.hpp>](../../../include/xieite/math/Integer.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr xieite::math::Integer<bits, sign> operator+=(xieite::math::Integer<bits, sign> integer) noexcept;
```
### Parameters
- `integer` - A `xieite::math::Integer` of `bits` and `sign`
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	xieite::math::Integer<4, false> integer = 5;

	integer += 2;

	std::cout << integer << '\n';
}
```
Output:
```
7
```
