# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:detectCosmicRay
Defined in header [<xieite/memory/detect_cosmic_ray.hpp>](../../../include/xieite/memory/detect_cosmic_ray.hpp)

&nbsp;

## Description
Detects rare cosmic rays or a faulty memory. Even if you do intercept something, you won't know which it is. Why would you use this?

&nbsp;

## Synopses
#### 1)
```cpp
template<std::unsigned_integral Chunk = std::uintmax_t>
constexpr void detectCosmicRay(std::size_t detectionBytes) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/memory/detect_cosmic_ray.hpp>
#include <xieite/memory/get_available.hpp>

int main() {
    xieite::memory::detectCosmicRay(xieite::memory::getAvailable());

    std::cout << "Cosmic ray detected!\n";
}
```
