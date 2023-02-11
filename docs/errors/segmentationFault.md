# xieite::errors::segmentationFault
Declared in `<xieite/errors/segmentationFault.hpp>`

<br/>

Creates a segmentation fault. Why would you do this?

<br/><br/>

## Declaration
```cpp
void segmentationFault() noexcept;
```

<br/><br/>

## Example
```cpp
#include <xieite/errors/segmentationFault.hpp>

int main() {
	xieite::errors::segmentationFault();
}
```
Output:
```
Segmentation fault (core dumped)
```
