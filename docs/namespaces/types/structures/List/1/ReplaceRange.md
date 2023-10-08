# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:ReplaceRange
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

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
#include <xieite/types/List.hpp>
#include <xieite/types/name.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Replace<2, 1, xieite::types::List<float, double>>;

    std::cout << xieite::types::name<List>() << '\n';
}
```
Output:
```
List<int, char, float, double, long>
```
