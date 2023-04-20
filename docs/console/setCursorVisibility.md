# `xieite::console::setCursorVisibility`
Defined in header [`<xieite/console/setCursorVisibility.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/setCursorVisibility.hpp)

<br/>

Shows or hides the cursor.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setCursorVisibility(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to show or hide the cursor
### Return value
- A `std::string`, the ANSI escape sequence to print
