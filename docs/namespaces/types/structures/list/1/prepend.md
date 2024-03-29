# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Prepend
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Prepends types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... OtherTypes>
using Prepend = xieite::types::List<Types..., OtherTypes...>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Prepend<float, double>;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<float, double, int, char, short, long>
```
