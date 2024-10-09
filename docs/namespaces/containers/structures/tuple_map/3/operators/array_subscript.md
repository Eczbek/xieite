# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<Key>, Value>](../../../../tuple_map.md)\:\:operator\[\]\<\>\(\)
Defined in fragment [xieite:containers.TupleMap](../../../../../../../src/containers/tuple_map.cpp)

&nbsp;

## Description
Extracts a value by a key.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, std::convertible_to<std::tuple<Key>> KeyReference>
[[nodiscard]] constexpr auto&& operator[](this Self&&, KeyReference&& key)
XIEITE_ARROW_BASE(/* ... */)
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
