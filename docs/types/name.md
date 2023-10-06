# [xieite](../xieite.md)\:\:[types](../types.md)\:\:name
Defined in header [<xieite/types/name.hpp>](../../include/xieite/types/name.hpp)

&nbsp;

## Description
Gets the string name of a type. Allows compile-time evaluation.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
constexpr std::string_view name() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/types/name.hpp>

int main() {
    std::cout << xieite::types::name<std::vector<int>>() << '\n';
}
```
Output:
```
std::vector<int>
```
