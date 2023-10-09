# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../list.md)\:\:Insert
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Inserts values.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t index, typename... OtherTypes>
using Insert = List<Types...>::Slice<0, index>::template Append<OtherTypes...>::template AppendRange<List<Types...>::Slice<index>>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Insert<2, float, double>;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<int, char, float, double, short, long>
```
