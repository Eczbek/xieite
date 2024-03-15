# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Erase
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Erases one or a range of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start, std::size_t end = start + 1>
using Erase = List<Types...>::Slice<0, start>::template AppendRange<List<Types...>::Slice<end>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Erase<2>;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<int, char, long>
```
