# [`xieite`](../../../README.md)`::`[`math`](../../../docs/math.md)`::`[`Integer<bits, sign>`](../../../docs/math/Integer.md)`::operator<<`
Defined in header [`<xieite/math/Integer.hpp>`](../../../include/xieite/math/Integer.hpp)

<br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator>>=(std::size_t distance) const noexcept;
```
### Parameters
- `distance` - A `std::size_t` copy, how far to shift leftward
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	xieite::math::Integer<4, false> integer = 5;

	integer >>= 2;

	std::cout << integer << '\n';
}
```
Output:
```
1
```
