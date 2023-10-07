# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:Replace
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

&nbsp;

Replaces a range with values.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t start, std::size_t end, typename... OtherTypes>
using Replace = List<Types...>::Erase<start, end>::template Insert<start, OtherTypes...>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Replace<2, 1, float, double>;

    std::cout << xieite::types::demangle(typeid(List).name()) << '\n';
}
```
Output:
```
xieite::types::List<int, char, float, double, long>
```
