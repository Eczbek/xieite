# [xieite](../../../xieite.md)\:\:[types](../../../types.md)\:\:[List\<Types...\>](../../List.md)\:\:Last
Defined in header [<xieite/types/List.hpp>](../../../../include/xieite/types/List.hpp)

&nbsp;

Accesses the last type.

&nbsp;

## Synopses
#### 1)
```cpp
using Last = List<Types...>::At<sizeof...(Types) - 1>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>;
    using Type = List::Last;

    std::cout << xieite::types::demangle(typeid(Type).name()) << '\n';
}
```
Output:
```
long
```
