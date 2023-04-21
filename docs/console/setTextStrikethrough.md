# `xieite::console::setTextStrikethrough`
Defined in header [`<xieite/console/setTextStrikethrough.hpp>`](../../include/xieite/console/setTextStrikethrough.hpp)

<br/>

Enables or disables ~~strikethrough~~ text.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextStrikethrough(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable strikethrough text
### Return value
- A `std::string`, the ANSI escape sequence to print
