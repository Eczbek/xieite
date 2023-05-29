# [xieite](../../README.md)::[terminal](../terminal.md)::setColorDimness
Defined in header [<xieite/terminal/setColorDimness.hpp>](../../include/xieite/terminal/setColorDimness.hpp)

<br/>

Enables or disables the "dimming" of foreground and background colors

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setColorDimness(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable dim colors
### Return value
- A `std::string`, the ANSI escape sequence to print