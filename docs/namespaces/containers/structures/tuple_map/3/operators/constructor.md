# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<Key>, Value>](../../../../tuple_map.md)\:\:TupleMap\(\)
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Constructs a `xieite::containers::TupleMap`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr TupleMap(std::initializer_list<std::pair<Key, Value>> list = {}) noexcept;
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

    std::println("{}", map[std::make_tuple(5)]);
}
```
Output:
```
3.14159
```
