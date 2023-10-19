# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:AppendRange
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Appends a list of types.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Range>
using AppendRange = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::AppendRange<xieite::types::List<float, double>>;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<int, char, short, long, float, double>
```
