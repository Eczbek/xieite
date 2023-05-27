# [xieite](../../../README.md)::[math](../../math.md)::[Integer<bits, sign>](../Integer.md)::operator<<
Defined in header [<xieite/math/Integer.hpp>](../../../include/xieite/math/Integer.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator<<(std::size_t distance) const noexcept;
```
### Parameters
- `distance` - A `std::size_t` copy, how far to shift leftward
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

```cpp
friend constexpr std::ostream& operator<<(std::ostream& outStream, xieite::math::Integer<bits, sign> self) noexcept;
```
### Parameters
- `outStream` - A `std::ostream` reference
- `self` - A `xieite::math::Integer` of `bits` and `sign`
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	std::cout << (xieite:math::Integer<8, false>(5) << 2) << '\n';
}
```
Output:
```
20
```
