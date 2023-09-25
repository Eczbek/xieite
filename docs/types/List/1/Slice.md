# [xieite](../../../xieite.md)\:\:[types](../../../types.md)\:\:[List\<Types...\>](../../List.md)\:\:Slice
Defined in header [<xieite/types/List.hpp>](../../../../include/xieite/types/List.hpp)

&nbsp;

Selects a "slice" from the stored list of types. Allows indices out of bounds and in any order.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t start, std::size_t end = sizeof...(Types)>
using Slice = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Slice<1, 3>;

    std::cout << xieite::types::demangle(typeid(List).name()) << '\n';
}
```
Output:
```
xieite::types::List<char, short>
```
