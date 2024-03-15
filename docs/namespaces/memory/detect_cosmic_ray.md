# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:detectCosmicRay\(\)
Defined in header [<xieite/memory/detect_cosmic_ray.hpp>](../../../include/xieite/memory/detect_cosmic_ray.hpp)

&nbsp;

## Description
Detects rare cosmic rays or a faulty memory. Even if you do intercept something, you won't know which it is. Why would you use this?

&nbsp;

## Synopsis
#### 1)
```cpp
inline void detectCosmicRay(std::size_t bytes) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/memory/detect_cosmic_ray.hpp"
#include "xieite/memory/get_available.hpp"

int main() {
    xieite::memory::detectCosmicRay(xieite::memory::getAvailable());

    std::println("Cosmic ray detected!");
}
```
Theoretical output:
```
Cosmic ray detected!
```
