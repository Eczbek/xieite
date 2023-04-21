# `xieite::console::ModeLock::echo`
Defined in header [`<xieite/console/ModeLock.hpp>`](../../../include/xieite/console/ModeLock.hpp)

<br/>

Enables or disables input signals. Specifically, disables the special functions of `Ctrl C`, `Ctrl Z`, `Ctrl S`, `Ctrl Q`, `Ctrl V`, and `Ctrl M`, to instead read them as a sequence of normal characters. Disabled by default.

<br/><br/>

## Synopsis

<br/>

```cpp
void setSignals(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to enable or disable signals.

<br/><br/>

## See also
- [`xieite::console::ModeLock`](../../../docs/console/ModeLock.md)
