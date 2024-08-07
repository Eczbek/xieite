# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:getTotal\(\)
Defined in header [<xieite/memory/get_total.hpp>](../../../include/xieite/memory/get_total.hpp)

&nbsp;

## Description
Gets the system's total amount of memory. Requires at least one of `XIEITE_PLATFORM_TYPE_UNIX` or `XIEITE_PLATFORM_TYPE_WINDOWS` to be true.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] inline std::size_t getTotal() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/memory/get_total.hpp"

int main() {
    std::println("{}", xieite::memory::getTotal());
}
```
Possible output:
```
16630874112
```
