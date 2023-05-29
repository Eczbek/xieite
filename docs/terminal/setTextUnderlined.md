# [xieite](../../README.md)::[terminal](../terminal.md)::setTextUnderlined
Defined in header [<xieite/terminal/setTextUnderlined.hpp>](../../include/xieite/terminal/setTextUnderlined.hpp)

<br/>

Enables or disables text <u>underlining</u>

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextUnderlined(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable text underlining
### Return value
- A `std::string`, the ANSI escape sequence to print
