# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<Key>, Value>](../../../../tuple_map.md)\:\:operator\[\]\(\)
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Extracts a value by a key.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, std::convertible_to<std::tuple<Key>> KeyReference>
[[nodiscard]] constexpr std::convertible_to<Value> auto&& operator[](this Self&& self, KeyReference&& key);
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
    std::println("{}", map[std::make_tuple(-23)]);
}
```
Output:
```
3.14159
2.71828
```
