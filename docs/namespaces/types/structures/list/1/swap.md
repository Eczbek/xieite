# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Swap
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Swaps two types by indices.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t index1, std::size_t index2>
using Swap = List<Types...>::template Set<index1, List<Types...>::At<index2>>::template Set<index2, List<Types...>::At<index1>>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Swap<1, 3>;

    std::cout << xieite::types::name<List> << '\n';
}
```
Output:
```
xieite::types::List<int, long, short, char>
```
