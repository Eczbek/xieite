# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:name
Defined in header [<xieite/types/name.hpp>](../../../include/xieite/types/name.hpp)

&nbsp;

## Description
Gets the string name of a type at compile-time.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
inline constexpr std::string_view name = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include <vector>
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<std::vector<int>>);
}
```
Possible output:
```
std::vector<int>
```
