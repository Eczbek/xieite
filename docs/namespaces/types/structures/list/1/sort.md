# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Sort\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Sorts types by name.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Functor<bool(std::string_view, std::string_view)> Comparator>
requires(std::is_default_constructible_v<Comparator>)
using Sort = /* xieite::types::List<...> */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"
#include "xieite/types/name.hpp"

struct Foo {};

int main() {
    using List = xieite::types::List<int, char, Foo, float>::Sort<std::ranges::less>;

    std::println("{}", xieite::types::name<List>);
}
```
Possible output:
```
xieite::types::List<Foo, char, float, int>
```
