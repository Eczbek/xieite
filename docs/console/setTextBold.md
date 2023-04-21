# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::setTextBold`
Defined in header [`<xieite/console/setTextBold.hpp>`](../../include/xieite/console/setTextBold.hpp)

<br/>

Enables or disables text **boldness**.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextBold(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable text boldness
### Return value
- A `std::string`, the ANSI escape sequence to print