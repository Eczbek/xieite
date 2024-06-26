# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:has\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Checks if the list contains a particular type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
static constexpr bool has = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"

int main() {
    using List = xieite::types::List<int, int, char, int, char, char, int>;

    std::println("{}", List::has<int>);
    std::println("{}", List::has<float>);
}
```
Possible output:
```
true
false
```
