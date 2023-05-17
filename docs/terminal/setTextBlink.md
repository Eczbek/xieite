# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::setTextBlink`
Defined in header [`<xieite/terminal/setTextBlink.hpp>`](../../include/xieite/terminal/setTextBlink.hpp)

<br/>

Enables or disables text blinking.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextBlink(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable text blinking
### Return value
- A `std::string`, the ANSI escape sequence to print
