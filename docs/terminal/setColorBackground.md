# [xieite](../../README.md)::[terminal](../terminal.md)::setColorBackground
Defined in header [<xieite/terminal/setColorBackground.hpp>](../../include/xieite/terminal/setColorBackground.hpp)

<br/>

Sets the text background color. Disregards alpha value of the passed argument

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setColorBackground(const xieite::graphics::Color& color) noexcept;
```
### Parameters
- `color` - A `xieite::graphics::Color` constant reference, to color the background
### Return value
- `std::string` - The resulting ANSI escape sequence to print
