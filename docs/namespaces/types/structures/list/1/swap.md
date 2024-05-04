# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:Swap\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Swaps two types by indices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t index1_, std::size_t index2_>
using Swap = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Swap<1, 3>;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<int, long, short, char>
```
