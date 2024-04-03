# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:identifier
Defined in header [<xieite/types/identifier.hpp>](../../../include/xieite/types/identifier.hpp)

&nbsp;

## Description
Gives unique identifiers to types. The identifiers are not guaranteed to be the same between compilations.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
inline constexpr std::size_t identifier = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/identifier.hpp"

int main() {
    std::println("{}", xieite::types::identifier<int>);
    std::println("{}", xieite::types::identifier<char>);
    std::println("{}", xieite::types::identifier<float>);
    std::println("{}", xieite::types::identifier<int>);
}
```
Possible output:
```
0
1
2
1
```
