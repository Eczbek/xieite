# [`xieite`](../../../README.md)`::`[`graphics`](../../../docs/graphics.md)`::`[`Color`](../../../docs/graphics/Color.md)`::value`
Defined in header [`<xieite/graphics/Color.hpp>`](../../../include/xieite/graphics/Color.hpp)

<br/>

Shifts and adds RGBA values together to create a single value.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::uint32_t value() noexcept;
```
### Return value
- The combined value

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/graphics/Color.hpp>

int main() {
	xieite::graphics::Color color(255, 127, 0);

	std::cout
		<< std::hex
		<< color.value()
		<< '\n';
}
```
Output:
```
ff7f00ff
```
