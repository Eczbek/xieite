# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<Key>, Value>](../../../tuple_map.md)\:\:contains\<\>\(\)
Defined in fragment [xieite:containers.TupleMap](../../../../../../src/containers/tuple_map.cpp)

&nbsp;

## Description
Checks if a value exists by a key.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<Key>> KeyReference>
[[nodiscard]] constexpr bool contains(KeyReference&& key) const
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

    std::println("{}", map.contains(std::make_tuple(5)));
    std::println("{}", map.contains(std::make_tuple(999)));
}
```
Output:
```
true
false
```
