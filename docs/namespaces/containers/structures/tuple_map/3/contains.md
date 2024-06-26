# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleMap<Container_, std::tuple<Key_>, Value_>](../../../tuple_map.md)\:\:contains\<\>\(\)
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Checks if a value exists by a key.

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
#include <unordered_map>
#include "xieite/containers/tuple_map.hpp"

int main() {
    using TupleMap = xieite::containers::TupleMap<std::unordered_map, std::tuple<int>, double>;

    TupleMap map = {
        { 5, 3.14159 },
        { -23, 2.71828 }
    };

    std::println("{}", map.contains(std::make_tuple(5)));
    std::println("{}", map.contains(std::make_tuple(999)));
}
```
Output:
```
true
false
```
