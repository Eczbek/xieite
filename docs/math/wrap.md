# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::wrap`
Defined in header [`<xieite/math/wrap.hpp>`](../../include/xieite/math/wrap.hpp)

<br/>

"Wraps" a number between two limits, inclusively.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number wrap(Number value, Number max, Number min = 0.0) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number` copy, the value to wrap
- `max` - A `Number` copy, the inclusive maximum of the result
- `min` - A `Number` copy, the inclusive minimum of the result. Set to `0.0` by default
### Return value
- A `Number`, the `value` wrapped between `max` and `min`

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
