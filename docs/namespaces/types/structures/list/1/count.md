# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types...>](../../../list.md)\:\:count\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Counts the instances of a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename, typename> typename Comparator = std::is_same>
static constexpr std::size_t count = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"

int main() {
    using List = xieite::types::List<int, int, char, int, char, char, int>;

    std::println("{}", List::count<int>);
}
```
Possible output:
```
4
```
