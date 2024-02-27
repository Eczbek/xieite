# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<Key>, Value>](../../../tuple_map.md)\:\:insert
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Assigns a value to a key.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<Key>> KeyReference, std::convertible_to<Value> ValueReference>
constexpr void insert(KeyReference&& key, ValueReference&& value);
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
        { 5, 3.14159 }
    };

    map.insert(std::make_tuple(-23), 2.71828);

    std::println("{}", map[std::make_tuple(-23)]);
}
```
Output:
```
2.71828
```
