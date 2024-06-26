# [xieite](../../../../../xieite.md)\:\:[types](../../../../../types.md)\:\:[List<Types_...>](../../../list.md)\:\:find\<\>
Defined in header [<xieite/types/list.hpp>](../../../../../../include/xieite/types/list.hpp)

&nbsp;

## Description
Finds the index of a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename, typename> typename Comparator_ = std::is_same>
requires(xieite::types::List<Types_...>::has<Type_, Comparator_>)
static constexpr std::size_t find = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/list.hpp"

int main() {
    using List = xieite::types::List<int, char, float, double, void, short, long, bool>;

    std::println("{}", List::find<double>);
}
```
Possible output:
```
3
```
