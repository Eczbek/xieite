# [xieite](../xieite.md)::[math](../math.md)::wrap
Defined in header [<xieite/math/wrap.hpp>](../../include/xieite/math/wrap.hpp)

<br/>

"Wraps" a number between two limits, inclusively

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2, xieite::concepts::Arithmetic Number3>
[[nodiscard]]
constexpr std::common_type_t<Number1, Number2, Number3> wrap(const Number1 value, const Number2 maximum, const Number3 minimum = 0.0) noexcept;
```
### Template parameters
- `Number1` - A type satisfying `xieite::concepts::Arithmetic`
- `Number2` - A type satisfying `xieite::concepts::Arithmetic`
- `Number3` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number1`, the value to wrap
- `maximum` - A `Number2`, the inclusive maximum of the result
- `minimum` - A `Number3`, the inclusive minimum of the result, set to `0.0` by default
### Return value
- A `std::common_type_t` of `Number1`, `Number2`, and `Number3`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/wrap.hpp>

int main() {
	std::cout << xieite::math::wrap(23, 4, -2) << '\n';
}
```
Output:
```
-1
```
