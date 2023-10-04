# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:[StandardController](../../StandardController.md)\:\:echo
Defined in header [<xieite/streams/StandardController.hpp>](../../../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Description
Enables or disables input signals. Specifically, disables the special functionalities of Ctrl+C, Ctrl+Z, Ctrl+S, Ctrl+Q, Ctrl+V, and Ctrl+M, to instead read them as a sequence of normal characters.

&nbsp;

## Synopses
#### 1)
```cpp
void setInputSignals(bool value) const noexcept;
```
