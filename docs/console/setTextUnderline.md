# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::setTextUnderline`
Defined in header [`<xieite/console/setTextUnderline.hpp>`](../../include/xieite/console/setTextUnderline.hpp)

<br/>

Enables or disables text <u>underlining</u>.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextUnderline(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable text underlining
### Return value
- A `std::string`, the ANSI escape sequence to print