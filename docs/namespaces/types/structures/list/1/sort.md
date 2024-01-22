# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:Sort
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

Sorts types by name.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Functable<bool(std::string_view, std::string_view)> Comparator>
requires(std::is_default_constructible_v<Comparator>)
using Sort = /* ... */;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/types/list.hpp>
#include <xieite/types/name.hpp>

struct Foo {};

int main() {
    using List = xieite::types::List<int, char, Foo, float>::Sort<std::ranges::less>;

    std::cout << xieite::types::name<List> << '\n';
}
```
Output:
```
xieite::types::List<Foo, char, float, int>
```
