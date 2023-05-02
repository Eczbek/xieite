# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::setTextUnderline`
Defined in header [`<xieite/terminal/setTextUnderline.hpp>`](../../include/xieite/terminal/setTextUnderline.hpp)

<br/>

Enables or disables text <u>underlining</u>.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
constexpr std::string setTextUnderline(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable text underlining
### Return value
- A `std::string`, the ANSI escape sequence to print
