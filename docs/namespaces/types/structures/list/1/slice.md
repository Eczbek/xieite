# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:Slice\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Selects a "slice" from the stored list of types. Allows indices out of bounds and in any order.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start_, std::size_t end_ = sizeof...(Types_)>
using Slice = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Slice<1, 3>;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<char, short>
```
