# [xieite](../xieite.md)\:\:[system](../system.md)\:\:segmentationFault
Defined in header [<xieite/system/segmentationFault.hpp>](../../include/xieite/system/segmentationFault.hpp)

&nbsp;

## Description
Creates a segmentation fault. Why would you use this?

&nbsp;

## Synopsis
```cpp
inline void segmentationFault() noexcept;
```

&nbsp;

## Example
```cpp
#include <xieite/system/segmentationFault.hpp>

int main() {
    xieite::system::segmentationFault();
}
```
Possible output:
```
Segmentation fault (core dumped)
```
