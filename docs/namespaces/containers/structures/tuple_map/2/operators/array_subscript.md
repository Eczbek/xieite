# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleMap<Container, std::tuple<FirstKey, RestKeys...>, Value>](../../../../tuple_map.md)\:\:operator\[\]\<\>\(\)
Defined in fragment [xieite:containers.TupleMap](../../../../../../../src/containers/tuple_map.cpp)

&nbsp;

## Description
Extracts a value by a specific combination of keys.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, std::convertible_to<std::tuple<FirstKey, RestKeys...>> KeysReference>
[[nodiscard]] constexpr auto&& operator[](this Self&&, KeysReference&& keys);
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

    std::println("{}", map[std::make_tuple(5, 'h')]);
    std::println("{}", map[std::make_tuple(5, '4')]);
    std::println("{}", map[std::make_tuple(-23, 'L')]);
    std::println("{}", map[std::make_tuple(-23, ' ')]);
}
```
Output:
```
3.14159
2.71828
6.28318
0.33333
```
