# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::setColorDim`
Defined in header [`<xieite/terminal/setColorDim.hpp>`](../../include/xieite/terminal/setColorDim.hpp)

<br/>

Enables or disables the "dimming" of foreground and background colors.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setColorDim(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable dim colors
### Return value
- A `std::string`, the ANSI escape sequence to print
