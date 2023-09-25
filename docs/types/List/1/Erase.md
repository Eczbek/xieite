# [xieite](../../../xieite.md)\:\:[types](../../../types.md)\:\:[List\<Types...\>](../../List.md)\:\:Erase
Defined in header [<xieite/types/List.hpp>](../../../../include/xieite/types/List.hpp)

&nbsp;

Erases one or a range of types.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t start, std::size_t end = start + 1>
using Erase = List<Types...>::Slice<0, start>::template AppendRange<List<Types...>::Slice<end>>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/demangle.hpp>

int main() {
    using List = xieite::types::List<int, char, short, long>::Erase<2>;

    std::cout << xieite::types::demangle(typeid(List).name()) << '\n';
}
```
Output:
```
xieite::types::List<int, char, long>
```
