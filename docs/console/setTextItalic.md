# `xieite::console::setTextItalic`
Defined in header [`<xieite/console/setTextItalic.hpp>`](../../include/xieite/console/setTextItalic.hpp)

<br/>

Enables or disables *italic* text.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextItalic(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable italic text
### Return value
- A `std::string`, the ANSI escape sequence to print
