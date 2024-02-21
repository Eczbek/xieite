# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setInputBlocking
Defined in header [<xieite/streams/standard_handle.hpp"](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables blocking mode. When disabled, any input reading will access the existing input buffer without waiting for new input.

&nbsp;

## Synopses
#### 1)
```cpp
void setInputBlocking(bool value) const noexcept;
```
