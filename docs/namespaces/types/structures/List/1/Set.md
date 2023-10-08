# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:Set
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

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
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Set<2, float>;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<int, char, float, long>
```
