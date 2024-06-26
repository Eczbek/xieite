# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleSet<Container_, std::tuple<Key_>>](../../../tuple_set.md)\:\:contains\(\)
Defined in header [<xieite/containers/tuple_set.hpp>](../../../../../../include/xieite/containers/tuple_set.hpp)

&nbsp;

## Description
Checks if the set contains a tuple.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<Key_>> KeyReference_>
[[nodiscard]] constexpr bool contains(KeyReference_&& key) const;
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include <unordered_set>
#include "xieite/containers/tuple_set.hpp"

int main() {
    using TupleSet = xieite::containers::TupleSet<std::unordered_set, std::tuple<int>>;

    TupleSet set = {
        { 5 },
        { 7 },
        { -23 },
        { 418 }
    };

    std::println("{}", set.contains(std::make_tuple(-23)));
    std::println("{}", set.contains(std::make_tuple(999)));
}
```
Output:
```
true
false
```
