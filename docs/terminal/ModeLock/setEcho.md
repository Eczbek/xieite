# [`xieite`](../../../README.md)`::`[`terminal`](../../../docs/terminal.md)`::`[`ModeLock`](../../../docs/terminal/ModeLock.md)`::setEcho`
Defined in header [`<xieite/terminal/ModeLock.hpp>`](../../../include/xieite/terminal/ModeLock.hpp)

<br/>

Enables or disables the echo. When echoing is disabled, pressed keys will not be visibly reflected in the terminal. Disabled by default.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
void setEcho(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy, determining whether to enable or disable echoing.
