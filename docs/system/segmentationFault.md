# [`xieite`](../../README.md)`::`[`system`](../../docs/system.md)`::segmentationFault`
Defined in header [`<xieite/system/segmentationFault.hpp>`](../../include/xieite/system/segmentationFault.hpp)

<br/>

Creates a segmentation fault. Why would you use this?

<br/><br/>

## Synopsis

<br/>

```cpp
[[noreturn]]
inline void segmentationFault() noexcept;
```

<br/><br/>

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
