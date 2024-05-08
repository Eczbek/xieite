# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:Insert\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Inserts a list of values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t index_, typename Range_>
using InsertRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Insert<2, xieite::types::List<float, double>>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<int, char, float, double, short, long>
```
