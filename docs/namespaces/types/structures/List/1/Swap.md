# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:Swap
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

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
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Swap<1, 3>;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<int, long, short, char>
```
