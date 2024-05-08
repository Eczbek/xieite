# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:ReplaceRange\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Replaces a range with a list of values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t start_, std::size_t end_, typename Range_>
using ReplaceRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::Replace<2, 1, xieite::types::List<float, double>>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<int, char, float, double, long>
```
