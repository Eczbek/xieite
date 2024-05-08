# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:PrependRange\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Prepends a list of types.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range_>
using PrependRange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using List = xieite::types::List<int, char, short, long>::PrependRange<xieite::types::List<float, double>>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<float, double, int, char, short, long>
```
