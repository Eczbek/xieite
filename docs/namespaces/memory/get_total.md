# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:getTotal\(\)
Defined in header [<xieite/memory/get_total.hpp>](../../../include/xieite/memory/get_total.hpp)

&nbsp;

## Description
Gets the system's total amount of memory.

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
