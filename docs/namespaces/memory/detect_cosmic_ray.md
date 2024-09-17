# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:detectCosmicRay\(\)
Defined in fragment [xieite:memory.detectCosmicRay](../../../src/memory/detect_cosmic_ray.cpp)

&nbsp;

## Description
Detects rare cosmic rays or a faulty memory. Even if you do intercept something, you won't know which it is. Why would you use this?

&nbsp;

## Synopsis
#### 1)
```cpp
void detectCosmicRay(std::size_t bytes) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::memory::detectCosmicRay(xieite::memory::getAvailable());

    std::println("Cosmic ray detected!");
}
```
Theoretical output:
```
Cosmic ray detected!
```
