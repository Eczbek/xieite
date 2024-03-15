# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Reverse
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Reverses the stored list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
using Reverse = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Reverse;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<long, short, char, int>
```
