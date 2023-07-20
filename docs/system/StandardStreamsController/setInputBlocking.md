# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::setInputBlocking
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Enables or disables blocking mode. When disabled, any input reading will access the existing input buffer without waiting for new input. Enabled by default

<br/><br/>

## Synopsis

<br/>

```cpp
void setInputBlocking(bool value) noexcept;
```
### Parameters
- `value` - A `bool` to determine whether to enable or disable blocking mode
