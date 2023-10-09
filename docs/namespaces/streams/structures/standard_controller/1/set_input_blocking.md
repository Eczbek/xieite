# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../standard_controller.md)\:\:setInputBlocking
Defined in header [<xieite/streams/standard_controller.hpp>](../../../../../../include/xieite/streams/standard_controller.hpp)

&nbsp;

## Description
Enables or disables blocking mode. When disabled, any input reading will access the existing input buffer without waiting for new input.

&nbsp;

## Synopses
#### 1)
```cpp
void setInputBlocking(bool value) const noexcept;
```
