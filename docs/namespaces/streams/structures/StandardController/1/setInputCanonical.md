# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../StandardController.md)\:\:setInputCanonical
Defined in header [<xieite/streams/StandardController.hpp>](../../../../../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Description
Enables or disables canonical mode. When it is disabled, the input is read by bytes instead of by lines, therefore anything typed is read immediately instead of waiting for a newline.

&nbsp;

## Synopses
#### 1)
```cpp
void setInputCanonical(bool value) const noexcept;
```
