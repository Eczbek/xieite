# [xieite](../xieite.md)::[math](../math.md)::absolute
Defined in header [<xieite/math/absolute.hpp>](../../include/xieite/math/absolute.hpp)

<br/>

Returns the absolute of a value

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr std::make_unsigned_t<Integral> absolute(Integral value) noexcept;
```
### Template parameters
- `Integral` - Any integral type satisfying `std::integral`
### Parameters
- `value` - An `Integral`
### Return value
- A `std::make_unsigned_t` of `Integral`, the absolute of `value`

<br/><br/>

```cpp
template<std::floating_point FloatingPoint>
[[nodiscard]]
constexpr FloatingPoint absolute(const FloatingPoint value) noexcept;
```
### Template parameters
- `FloatingPoint` - A floating point type satisfying `std::floating_point`
### Parameters
- `value` - A `FloatingPoint`
### Return value
- A `FloatingPoint`, the absolute of `value`

<br/><br/>

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <xieite/math/absolute.hpp>

int main() {
	std::int16_t value = -32768;
	
	std::cout << xieite::math::absolute(value) << '\n';
}
```
Output:
```
32768
```
