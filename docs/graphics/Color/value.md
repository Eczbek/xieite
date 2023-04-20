# `xieite::graphics::Color::value`
Defined in header [`<xieite/graphics/Color.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/graphics/Color.hpp)

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
	std::cout << std::hex
		<< xieite::graphics::Color(255, 127, 0).value() << '\n';
}
```
Output:
```
ff7f00ff
```
