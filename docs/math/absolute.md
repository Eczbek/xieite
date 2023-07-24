# [xieite](../xieite.md)::[math](../math.md)::absolute
Defined in header [<xieite/math/absolute.hpp>](../../include/xieite/math/absolute.hpp)

<br/>

Returns the absolute of a value. Unlike std::abs, this accepts both signed and unsigned arithmetic types

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr Arithmetic absolute(Arithmetic value) noexcept;
```
### Template parameters
- `Arithmetic` - Any arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - An `Arithmetic`
### Return value
- An `Arithmetic`, the absolute of value

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/absolute.hpp>

int main() {
	int a = -17;
	unsigned b = 4;
	
	std::cout
		<< xieite::math::absolute(a) << '\n'
		<< xieite::math::absolute(b) << '\n';
}
```
Output:
```
17
4
```
