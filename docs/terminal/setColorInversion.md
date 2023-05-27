# [xieite](../../README.md)::[terminal](../terminal.md)::setColorInversion
Defined in header [<xieite/terminal/setColorInversion.hpp>](../../include/xieite/terminal/setColorInversion.hpp)

<br/>

Enables or disables the swapping of foreground and background colors

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setColorInversion(bool value) noexcept;
```
### Parameters
- `value` - A `bool` to determine whether to enable or disable color inversion
### Return value
- A `std::string`, the ANSI escape sequence to print
