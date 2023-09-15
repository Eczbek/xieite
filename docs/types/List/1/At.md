# [xieite](../../../xieite.md)\:\:[types](../../../types.md)\:\:[List\<Types...\>](../../List.md)\:\:At
Defined in header [<xieite/types/List.hpp>](../../../../include/xieite/types/List.hpp)

&nbsp;

Accesses a type by index.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t index>
using At = std::conditional_t<index < sizeof...(Types), std::tuple_element<index, List<Types...>::Data>, std::type_identity<void>>::type;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using Type = xieite::types::List<int, char, short, long>::At<2>;

    std::cout << xieite::types::demangle(typeid(Type).name()) << '\n';
}
```
Output:
```
short
```
