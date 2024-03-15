# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:SwapRanges
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Swaps two ranges of types by indices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
using SwapRanges = /* ... */;;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::SwapRanges<0, 2, 2, 4>;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<short, long, int, char>
```
