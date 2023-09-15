# [xieite](../../../xieite.md)\:\:[types](../../../types.md)\:\:[List\<Types...\>](../../List.md)\:\:Reverse
Defined in header [<xieite/types/List.hpp>](../../../../include/xieite/types/List.hpp)

&nbsp;

Reverses the stored list of types.

&nbsp;

## Synopses
#### 1)
```cpp
using Reverse = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Reverse;

    std::cout << xieite::types::demangle(typeid(List::Data).name()) << '\n';
}
```
Output:
```
std::tuple<long, short, char, int>
```
