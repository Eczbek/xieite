# [xieite](../../README.md)::[terminal](../terminal.md)::setColorForeground
Defined in header [<xieite/terminal/setColorForeground.hpp>](../../include/xieite/terminal/setColorForeground.hpp)

<br/>

Sets the text foreground color. Disregards alpha value of the passed argument

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setColorForeground(const xieite::graphics::Color& color) noexcept;
```
### Parameters
- `color` - A `xieite::graphics::Color` constant reference
### Return value
- A `std::string` - The resulting ANSI escape sequence to print
