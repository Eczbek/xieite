# [`xieite`](../../README.md)`::`[`errors`](../../docs/error.md)`::segmentationFault`
Defined in header [`<xieite/errors/segmentationFault.hpp>`](../../include/xieite/errors/segmentationFault.hpp)

<br/>

Creates a segmentation fault. Why would you do this?

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
#include <xieite/errors/segmentationFault.hpp>

int main() {
	xieite::errors::segmentationFault();
}
```
Possible output:
```
Segmentation fault (core dumped)
```
