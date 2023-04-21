# `xieite::math::Integer<bits, sign>::operator<<`
Defined in header [`<xieite/math/Integer.hpp>`](../../../include/xieite/math/Integer.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator<<=(std::size_t distance) const noexcept;
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
	xieite::math::Integer<8, false> integer = 5;

	integer <<= 2;

	std::cout << integer << '\n';
}
```
Output:
```
20
```

<br/><br/>

## See also
- [`xieite::math::Integer`](../../../docs/math/Integer.md)
