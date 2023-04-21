# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::setCursorVisibility`
Defined in header [`<xieite/console/setCursorVisibility.hpp>`](../../include/xieite/console/setCursorVisibility.hpp)

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
