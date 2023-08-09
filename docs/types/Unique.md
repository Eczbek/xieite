# [xieite](../xieite.md)\:\:[types](../types.md)\:\:Unique
Defined in header [<xieite/types/Unique.hpp>](../../include/xieite/types/Unique.hpp)

&nbsp;

## Description
Creates a `xieite::types::List` using only unique types of those provided.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Types>
using Unique = decltype((xieite::types::List<>()->*...->*xieite::types::List<Types>()));
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/Unique.hpp>

int main() {
    std::cout
        << std::boolalpha
        << std::same_as<
            xieite::types::List<int, char>,
            xieite::types::Unique<int, int, char, int, char, char, int>
        > << '\n';
}
```
Output:
```
true
```
