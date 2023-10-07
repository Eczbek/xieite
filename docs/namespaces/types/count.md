# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:count
Defined in header [<xieite/types/count.hpp>](../../../include/xieite/types/count.hpp)

&nbsp;

## Description
Counts the number of template arguments passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Types>
inline constexpr std::size_t count = sizeof...(Types);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/count.hpp>

int main() {
    std::cout << xieite::types::count<int, int, int> << '\n';
}
```
Output:
```
3
```
