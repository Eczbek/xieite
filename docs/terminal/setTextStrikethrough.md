# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::setTextStrikethrough`
Defined in header [`<xieite/terminal/setTextStrikethrough.hpp>`](../../include/xieite/terminal/setTextStrikethrough.hpp)

<br/>

Enables or disables ~~strikethrough~~ text.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
constexpr std::string setTextStrikethrough(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable strikethrough text
### Return value
- A `std::string`, the ANSI escape sequence to print
