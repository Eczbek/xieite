# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key, Value, size, Hash, KeyComparator, Allocator>](../../../../fixed_map.md)\:\:operator\[\]\(\)
Defined in header [<xieite/containers/fixed_map.hpp>](../../../../../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
Accesses a value by its key, if it exists.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, std::convertible_to<Key> KeyReference>
[[nodiscard]] constexpr std::expected<auto&&, xieite::errors::Type> operator[](this Self&&, KeyReference&& key);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/fixed_map.hpp"

int main() {
    xieite::containers::FixedMap<int, double, 3> map = {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };

    for (int i = 1; i <= 3; ++i) {
        std::println("{}: {}", i, map[i].value());
    }
}
```
Output:
```
1: 2.71828
2: 3.14159
2: 6.28318
```
