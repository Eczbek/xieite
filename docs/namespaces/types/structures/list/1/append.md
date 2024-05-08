# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:Append\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Appends types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... OtherTypes_>
using Append = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Append<float, double>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<int, char, short, long, float, double>
```
