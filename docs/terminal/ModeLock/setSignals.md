# [xieite](../../../README.md)::[terminal](../../terminal.md)::[ModeLock](../ModeLock.md)::echo
Defined in header [<xieite/terminal/ModeLock.hpp>](../../../include/xieite/terminal/ModeLock.hpp)

<br/>

Enables or disables input signals. Specifically, disables the special functions of Ctrl+C, Ctrl+Z, Ctrl+S, Ctrl+Q, Ctrl+V, and Ctrl+M, to instead read them as a sequence of normal characters. Disabled by default

<br/><br/>

## Synopsis

<br/>

```cpp
void setSignals(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to enable or disable signals.
