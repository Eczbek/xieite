# [xieite](../../../README.md)::[terminal](../../terminal.md)::[ModeLock](../ModeLock.md)::setBlocking
Defined in header [<xieite/terminal/ModeLock.hpp>](../../../include/xieite/terminal/ModeLock.hpp)

<br/>

Enables or disables blocking mode. When disabled, any input reading will access the existing input buffer without waiting for new input. Enabled by default

<br/><br/>

## Synopsis

<br/>

```cpp
void setBlocking(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to enable or disable blocking mode
