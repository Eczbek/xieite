# `xieite::console::setColorBackground`
Defined in header [`<xieite/console/setColorBackground.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/setColorBackground.hpp)

<br/>

Sets the text background color. Disregards alpha value of the passed argument.

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

<br/><br/>

## See also
- [`xieite::graphics::Color`](https://github.com/Eczbek/xieite/tree/main/docs/graphics/Color.md)
