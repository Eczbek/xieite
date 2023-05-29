# [xieite](../../README.md)::[terminal](../terminal.md)::setTextStriked
Defined in header [<xieite/terminal/setTextStriked.hpp>](../../include/xieite/terminal/setTextStriked.hpp)

<br/>

Enables or disables ~~strikethrough~~ text

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextStriked(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable strikethrough text
### Return value
- A `std::string`, the ANSI escape sequence to print
