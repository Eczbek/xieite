# [`xieite`](../../../README.md)`::`[`math`](../../../docs/math.md)`::`[`Integer<bits, sign>`](../../../docs/math/Integer.md)`::operator|`
Defined in header [`<xieite/math/Integer.hpp>`](../../../include/xieite/math/Integer.hpp)

<br/>

## Synopsis

<br/><br/>

```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator|(xieite::math::Integer<bits, sign> integer) const noexcept;
```
### Parameters
- `integer` - A `xieite::math::Integer` copy of `bits` and `sign`
### Return value
- A `xieite::math::Integer` of `bits` and `sign`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

int main() {
	std::cout << (xieite:math::Integer<4, false>(5) | 2) << '\n';
}
```
Output:
```
7
```
