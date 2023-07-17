# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::echo
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Enables or disables input signals. Specifically, disables the special functions of Ctrl+C, Ctrl+Z, Ctrl+S, Ctrl+Q, Ctrl+V, and Ctrl+M, to instead read them as a sequence of normal characters. Disabled by default

<br/><br/>

## Synopsis

<br/>

```cpp
void setInputSignals(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to enable or disable signals.
