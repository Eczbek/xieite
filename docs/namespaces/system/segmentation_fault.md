# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:segmentationFault\(\)
Defined in fragment [xieite:system.segmentationFault](../../../src/system/segmentation_fault.cpp)

&nbsp;

## Description
Causes a segmentation fault. Why would you use this?

&nbsp;

## Synopsis
#### 1)
```cpp
void segmentationFault() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::system::segmentationFault();
}
```
Possible output:
```
Segmentation fault (core dumped)
```
