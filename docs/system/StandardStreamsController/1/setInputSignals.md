# [xieite](../../../xieite.md)\:\:[system](../../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../../StandardStreamsController.md)\:\:echo
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Enables or disables input signals. Specifically, disables the special functionalities of Ctrl+C, Ctrl+Z, Ctrl+S, Ctrl+Q, Ctrl+V, and Ctrl+M, to instead read them as a sequence of normal characters.

&nbsp;

## Synopses
#### 1)
```cpp
void setInputSignals(bool value) const noexcept;
```
