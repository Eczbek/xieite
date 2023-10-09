# [xieite](../../xieite.md)\:\:[memory](../../memory.md)\:\:getPageSize
Defined in header [<xieite/memory/get_page_size.hpp>](../../../include/xieite/memory/get_page_size.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] inline std::size_t getPageSize() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/memory/get_page_size.hpp>

int main() {
    std::cout << xieite::memory::getPageSize() << '\n';
}
```
Possible output:
```
4096
```
