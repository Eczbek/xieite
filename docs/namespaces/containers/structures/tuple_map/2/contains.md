# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<FirstKey, RestKeys...>, Value>](../../../tuple_map.md)\:\:contains\<\>\(\)
Defined in fragment [xieite:containers.TupleMap](../../../../../../src/containers/tuple_map.cpp)

&nbsp;

## Description
Checks if a value exists by a specific combination of keys.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
[[nodiscard]] constexpr bool contains(KeysReference&& keys) const;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using TupleMap = xieite::containers::TupleMap<std::unordered_map, std::tuple<int, char>, double>;

    TupleMap map = {
        { 5, {
            { 'h', 3.14159 },
            { '4', 2.71828 }
        } },
        { -23, {
            { 'L', 6.28318 },
            { ' ', 0.33333 }
        } }
    };

    std::println("{}", map.contains(std::make_tuple(-23, 'L')));
    std::println("{}", map.contains(std::make_tuple(999, 'q')));
}
```
Output:
```
true
false
```
