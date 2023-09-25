# [xieite](../../../xieite.md)\:\:[types](../../../types.md)\:\:[List\<Types...\>](../../List.md)\:\:Insert
Defined in header [<xieite/types/List.hpp>](../../../../include/xieite/types/List.hpp)

&nbsp;

Inserts a list of values.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t index, typename Range>
using InsertRange = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Insert<2, xieite::types::List<float, double>>;

    std::cout << xieite::types::demangle(typeid(List).name()) << '\n';
}
```
Output:
```
xieite::types::List<int, char, float, double, short, long>
```
