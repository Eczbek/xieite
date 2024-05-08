# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:Rearrange\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Rearranges the types within a list by their indices

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t... indices_>
using Rearrange = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

int main() {
    using Foo = xieite::types::List<int, char, short, long>;

    using Bar = Foo::Rearrange<3, 0, 2>;

    std::println("{}", xieite::types::name<Bar>);
}
```
Possible output:
```
xieite::types::List<long, int, short>
```
