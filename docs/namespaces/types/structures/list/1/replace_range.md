# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:ReplaceRange
Defined in header [<xieite/types/list.hpp"](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Replaces a range with a list of values.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t start, std::size_t end, typename Range>
using ReplaceRange = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Replace<2, 1, xieite::types::List<float, double>>;

    std::cout << xieite::types::name<List> << '\n';
}
```
Output:
```
xieite::types::List<int, char, float, double, long>
```
