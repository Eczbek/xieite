# `xieite::console::ModeLock::setCanonical`
Defined in header [`<xieite/console/ModeLock.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/ModeLock.hpp)

<br/>

Enables or disables canonical mode. When it is disabled, the input is read by bytes instead of by lines, therefore anything typed is read immediately instead of waiting for a newline. Disabled by default.

<br/><br/>

## Synopsis

<br/>

```cpp
void setCanonical(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to enable or disable canonical mode.

<br/><br/>

## See also
- [`xieite::console::ModeLock`](https://github.com/Eczbek/xieite/tree/main/docs/console/ModeLock.md)
