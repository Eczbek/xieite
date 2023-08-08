# [xieite](../xieite.md)\:\:[types](../types.md)\:\:count
Defined in header [<xieite/types/count.hpp>](../../include/xieite/types/count.hpp)

&nbsp;

## Description
Counts the number of types passed

&nbsp;

## Synopsis
```cpp
template<typename... Any>
inline constexpr std::size_t count = sizeof...(Any);
```
#### Template parameters
- `Any...` - Any types

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
