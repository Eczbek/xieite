# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:segmentationFault\(\)
Defined in header [<xieite/system/segmentation_fault.hpp>](../../../include/xieite/system/segmentation_fault.hpp)

&nbsp;

## Description
Creates a segmentation fault. Why would you use this?

&nbsp;

## Synopsis
#### 1)
```cpp
inline void segmentationFault() noexcept;
```

&nbsp;

## Example
```cpp
#include "xieite/system/segmentation_fault.hpp"

int main() {
    xieite::system::segmentationFault();
}
```
Possible output:
```
Segmentation fault (core dumped)
```
