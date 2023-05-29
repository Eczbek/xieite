# [xieite](../../README.md)::[terminal](../terminal.md)::setTextItalicized
Defined in header [<xieite/terminal/setTextItalicized.hpp>](../../include/xieite/terminal/setTextItalicized.hpp)

<br/>

Enables or disables *italic* text

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextItalicized(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable italic text
### Return value
- A `std::string`, the ANSI escape sequence to print
