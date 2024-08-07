# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:getAvailable\(\)
Defined in header [<xieite/memory/get_available.hpp>](../../../include/xieite/memory/get_available.hpp)

&nbsp;

## Description
Gets the system's currently available amount of memory. Requires at least one of `XIEITE_PLATFORM_TYPE_UNIX` or `XIEITE_PLATFORM_TYPE_WINDOWS` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] inline std::size_t getAvailable() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/memory/get_available.hpp"

int main() {
    std::println("{}", xieite::memory::getAvailable());
}
```
Possible output:
```
6001029120
```
