# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../standard_controller.md)\:\:setInputCanonical
Defined in header [<xieite/streams/standard_controller.hpp>](../../../../../../include/xieite/streams/standard_controller.hpp)

&nbsp;

## Description
Enables or disables canonical mode. When it is disabled, the input is read by bytes instead of by lines, therefore anything typed is read immediately instead of waiting for a newline.

&nbsp;

## Synopses
#### 1)
```cpp
void setInputCanonical(bool value) const noexcept;
```
