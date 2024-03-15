# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:getPageSize
Defined in header [<xieite/memory/get_page_size.hpp>](../../../include/xieite/memory/get_page_size.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] inline std::size_t getPageSize() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/memory/get_page_size.hpp"

int main() {
    std::println("{}", xieite::memory::getPageSize());
}
```
Possible output:
```
4096
```
