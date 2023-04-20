# `xieite::console::setTextVisibility`
Defined in header [`<xieite/console/setTextVisibility.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/setTextVisibility.hpp)

<br/>

Enables or disables text visibility.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setTextVisibility(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable text visibility
### Return value
- A `std::string`, the ANSI escape sequence to print
