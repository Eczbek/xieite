# [xieite](../xieite.md)\:\:[memory](../memory.md)\:\:getPageSize
Defined in header [<xieite/memory/getPageSize.hpp>](../../include/xieite/memory/getPageSize.hpp)

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
#include <xieite/memory/getPageSize.hpp>

int main() {
    std::cout << xieite::memory::getPageSize() << '\n';
}
```
Possible output:
```
4096
```
