# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::setColorForeground`
Defined in header [`<xieite/console/setColorForeground.hpp>`](../../include/xieite/console/setColorForeground.hpp)

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
- [`xieite::graphics::Color`](../../docs/graphics/Color.md)
