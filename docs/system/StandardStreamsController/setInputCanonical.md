# [xieite](../../xieite.md)::[system](../../system.md)::[StandardStreamsController<inputStream, outputStream>](../StandardStreamsController.md)::setInputCanonical
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

<br/>

Enables or disables canonical mode. When it is disabled, the input is read by bytes instead of by lines, therefore anything typed is read immediately instead of waiting for a newline. Disabled by default

<br/><br/>

## Synopsis

<br/>

```cpp
void setInputCanonical(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to enable or disable canonical mode
