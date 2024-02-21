# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:FixedSet
Defined in header [<xieite/types/list.hpp"](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Sets a type by index.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t index, typename OtherType>
using Set = List<Types...>::Erase<index>::template Insert<index, OtherType>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::FixedSet<2, float>;

    std::cout << xieite::types::name<List> << '\n';
}
```
Output:
```
xieite::types::List<int, char, float, long>
```
