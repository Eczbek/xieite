# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:setInputEcho
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Enables or disables the echo. When echoing is disabled, pressed keys will not be visibly reflected in the terminal. Disabled by default

&nbsp;

## Synopsis
```cpp
void setInputEcho(bool value) noexcept;
```
#### Function parameters
- `value` - A `bool`, determining whether to enable or disable echoing.
