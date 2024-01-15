# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Slice
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Selects one of each type from the stored list of types.

&nbsp;

## Synopses
#### 1)
```cpp
using Unique = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, int, char, int, char>::Unique;

    std::cout << xieite::types::name<List> << '\n';
}
```
Output:
```
xieite::types::List<int, char>
```
