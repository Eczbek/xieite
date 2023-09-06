# [xieite](../../../xieite.md)\:\:[system](../../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../../StandardStreamsController.md)\:\:setInputBlocking
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Enables or disables blocking mode. When disabled, any input reading will access the existing input buffer without waiting for new input. Enabled by default.

&nbsp;

## Synopses
#### 1)
```cpp
void setInputBlocking(bool value) noexcept;
```