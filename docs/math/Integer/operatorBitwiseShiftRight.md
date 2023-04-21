# `xieite::math::Integer<bits, sign>::operator>>`
Defined in header [`<xieite/math/Integer.hpp>`](../../../include/xieite/math/Integer.hpp)

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator>>(std::size_t distance) const noexcept;
```
### Parameters
- `distance` - A `std::size_t` copy, how far to shift rightward
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/>

```cpp
friend constexpr std::ostream& operator>>(std::ostream& inStream, xieite::math::Integer<bits, sign>& self) noexcept;
```
### Parameters
- `inStream` - A `std::ostream` reference
- `self` - A reference to a `xieite::math::Integer` of `bits` and `sign`
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	std::cout << (xieite:math::Integer<4, false>(5) >> 2) << '\n';
}
```
Output:
```
1 
```

<br/><br/>

## See also
- [`xieite::math::Integer`](../../../docs/math/Integer.md)
