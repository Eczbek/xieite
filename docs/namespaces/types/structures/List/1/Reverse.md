# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:Reverse
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

&nbsp;

Reverses the stored list of types.

&nbsp;

## Synopses
#### 1)
```cpp
using Reverse = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Reverse;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<long, short, char, int>
```