# `xieite::console::ModeLock::setBlocking`
Defined in header [`<xieite/console/ModeLock.hpp>`](../../../include/xieite/console/ModeLock.hpp)

<br/>

Enables or disables blocking mode. When disabled, any input reading will access the existing input buffer without waiting for new input. Enabled by default.

<br/><br/>

## Synopsis

<br/>

```cpp
void setBlocking(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable blocking mode

<br/><br/>

## See also
- [`xieite::console::ModeLock`](../../../docs/console/ModeLock.md)
