# `xieite::console::setColorInversion`
Defined in header [`<xieite/console/setColorInversion.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/setColorInversion.hpp)

<br/>

Enables or disables the swapping of foreground and background colors.

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
