# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List\<Types...\>](../../../List.md)\:\:size
Defined in header [<xieite/types/List.hpp>](../../../../../../include/xieite/types/List.hpp)

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
#include <xieite/types/List.hpp>

int main() {
    std::size_t size = xieite::types::List<int, char, short, long>::size;

    std::cout << size << '\n';
}
```
Output:
```
4
```
