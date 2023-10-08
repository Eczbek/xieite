# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:SwapRanges
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

&nbsp;

Swaps two ranges of types by indices.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
using SwapRanges = /* ... */;;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::SwapRanges<0, 2, 2, 4>;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<short, long, int, char>
```