# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:name\<\>
Defined in header [<xieite/types/name.hpp>](../../../include/xieite/types/name.hpp)

&nbsp;

## Description
Extracts the stringified name of a type at compile-time without additional formatting (very compiler-dependant).

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
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
