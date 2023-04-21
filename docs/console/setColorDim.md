# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::setColorDim`
Defined in header [`<xieite/console/setColorDim.hpp>`](../../include/xieite/console/setColorDim.hpp)

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
