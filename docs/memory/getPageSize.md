# [xieite](../xieite.md)\:\:[memory](../memory.md)\:\:getPageSize
Defined in header [<xieite/memory/getPageSize.hpp>](../../include/xieite/memory/getPageSize.hpp)

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
inline std::size_t getPageSize() noexcept;
```
#### Return type
- `std::size_t`

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
