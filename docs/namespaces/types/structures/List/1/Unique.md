# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:Slice
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

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
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, int, char, int, char>::Unique;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<int, char>
```