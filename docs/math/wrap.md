# [xieite](../xieite.md)::[math](../math.md)::wrap
Defined in header [<xieite/math/wrap.hpp>](../../include/xieite/math/wrap.hpp)

<br/>

"Wraps" a number between two limits, inclusively

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2, xieite::concepts::Arithmetic Arithmetic3>
[[nodiscard]]
constexpr std::common_type_t<Arithmetic1, Arithmetic2, Arithmetic3> wrap(const Arithmetic1 value, const Arithmetic2 maximum, const Arithmetic3 minimum = 0.0) noexcept;
```
### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic3` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - An `Arithmetic1`, the value to wrap
- `maximum` - An `Arithmetic2`, the inclusive maximum of the result
- `minimum` - An `Arithmetic3`, the inclusive minimum of the result, set to `0.0` by default
### Return value
- A `std::common_type_t` of `Arithmetic1`, `Arithmetic2`, and `Arithmetic3`

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
