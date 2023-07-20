# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::setInputEcho
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Enables or disables the echo. When echoing is disabled, pressed keys will not be visibly reflected in the terminal. Disabled by default

<br/><br/>

## Synopsis

<br/>

```cpp
void setInputEcho(bool value) noexcept;
```
### Parameters
- `value` - A `bool`, determining whether to enable or disable echoing.
