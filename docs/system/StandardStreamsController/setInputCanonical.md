# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:setInputCanonical
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Enables or disables canonical mode. When it is disabled, the input is read by bytes instead of by lines, therefore anything typed is read immediately instead of waiting for a newline. Disabled by default

&nbsp;

## Synopsis
```cpp
void setInputCanonical(bool value) noexcept;
```
#### Function parameters
- `value` - A `bool` to enable or disable canonical mode
