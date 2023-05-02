# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::setTextItalic`
Defined in header [`<xieite/terminal/setTextItalic.hpp>`](../../include/xieite/terminal/setTextItalic.hpp)

<br/>

Enables or disables *italic* text.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
constexpr std::string setTextItalic(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable italic text
### Return value
- A `std::string`, the ANSI escape sequence to print
