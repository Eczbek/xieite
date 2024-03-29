# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Replace
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Replaces a range with values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start, std::size_t end, typename... OtherTypes>
using Replace = List<Types...>::Erase<start, end>::template Insert<start, OtherTypes...>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Replace<2, 1, float, double>;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<int, char, float, double, long>
```
