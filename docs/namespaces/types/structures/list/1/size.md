# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:size
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

The number of types stored.

&nbsp;

## Synopses
#### 1)
```cpp
static constexpr std::size_t size = sizeof...(Types);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>

int main() {
    std::size_t size = xieite::types::List<int, char, short, long>::size;

    std::cout << size << '\n';
}
```
Output:
```
4
```
