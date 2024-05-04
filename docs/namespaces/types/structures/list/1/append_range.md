# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:AppendRange\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Appends a list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range_>
using AppendRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::AppendRange<xieite::types::List<float, double>>;

    std::println("{}", xieite::types::name<List>);
}
```
Output:
```
xieite::types::List<int, char, short, long, float, double>
```
