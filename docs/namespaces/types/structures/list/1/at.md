# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:At
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Accesses a type by index.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t index>
using At = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>
#include <xieite/types/name.hpp>

int main() {
    using Type = xieite::types::List<int, char, short, long>::At<2>;

    std::cout << xieite::types::name<Type>() << '\n';
}
```
Output:
```
short
```
