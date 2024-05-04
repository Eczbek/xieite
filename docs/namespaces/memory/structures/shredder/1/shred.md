# [xieite](../../../../../xieite.md)\:\:[memory](../../../../../memory.md)\:\:[Shredder<Type_>](../../../shredder.md)\:\:shred\(\)
Defined in header [<xieite/memory/shredder.hpp>](../../../../../../include/xieite/memory/shredder.hpp)

&nbsp;

## Description
Shreds the stored data.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr void shred() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/memory/shredder.hpp"

int main() {
    xieite::memory::Shredder<int> thing = 5;

    thing.shred();

    std::println("{}", thing.shred());
}
```
Output:
```
0
```
