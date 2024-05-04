# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[TupleMap<Container_, std::tuple<FirstKey_, RestKeys_...>, Value_>](../../../../tuple_map.md)\:\:operator\[\]\<\>\(\)
Defined in header [<xieite/containers/tuple_map.hpp>](../../../../../../../include/xieite/containers/tuple_map.hpp)

&nbsp;

## Description
Extracts a value by a specific combination of keys.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self_, std::convertible_to<std::tuple<FirstKey_, RestKeys_...>> KeysReference_>
[[nodiscard]] constexpr auto&& operator[](this Self_&&, KeysReference_&& keys);
```

&nbsp;

## Example
```cpp
#include <print>
#include <tuple>
#include <unordered_map>
#include "xieite/containers/tuple_map.hpp"

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
