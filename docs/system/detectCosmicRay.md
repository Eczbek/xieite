# [xieite](../../README.md)::[system](../system.md)::detectCosmicRay
Defined in header [<xieite/system/detectCosmicRay.hpp>](../../include/xieite/system/detectCosmicRay.hpp)

<br/>

Detects rare cosmic rays or a faulty memory. Even if you do intercept something, you won't know which it is. Why would you use this?

<br/><br/>

## Synopsis

<br/>

```cpp
inline void detectCosmicRay(std::size_t detectionBytes) noexcept;
```
### Parameters
- `detectionBytes` - The amount of bytes to constantly scan until something changes

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/system/detectCosmicRay.hpp>
#include <xieite/system/getAvailableMemory.hpp>

int main() {
	xieite::system::detectCosmicRay(xieite::system::getAvailableMemory());

	std::cout << "Cosmic ray detected!\n";
}
```
