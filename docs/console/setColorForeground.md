# `xieite::console::setColorForeground`
Defined in header [`<xieite/console/setColorForeground.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/setColorForeground.hpp)

<br/>

Sets the text foreground color. Disregards alpha value of the passed argument.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setColorForeground(const xieite::graphics::Color& color) noexcept;
```
### Parameters
- `color` - A `xieite::graphics::Color` constant reference
### Return value
- `std::string` - The resulting ANSI escape sequence to print

<br/><br/>

## See also
- [`xieite::graphics::Color`](https://github.com/Eczbek/xieite/tree/main/docs/graphics/Color.md)
