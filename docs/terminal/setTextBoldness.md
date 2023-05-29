# [xieite](../../README.md)::[terminal](../terminal.md)::setTextBoldness
Defined in header [<xieite/terminal/setTextBoldness.hpp>](../../include/xieite/terminal/setTextBoldness.hpp)

<br/>

Enables or disables text **boldness**

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextBoldness(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable text boldness
### Return value
- A `std::string`, the ANSI escape sequence to print
