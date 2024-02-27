# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[FixedMap<Key, Value, size, Hash, KeyComparator, Allocator>](../../../fixed_map.md)\:\:at
Defined in header [<xieite/containers/fixed_map.hpp>](../../../../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

Accesses a value by its key, if it exists. May throw `xieite::exceptions::InvalidKey` if the map does not contain a key that it is accessed with.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, std::convertible_to<Key> KeyReference>
[[nodiscard]] constexpr std::convertible_to<Value> auto&& at(this Self&& self, KeyReference&& key);
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
        std::println("{}: {}", i, map.at(i));
    }
}
```
Output:
```
1: 2.71828
2: 3.14159
2: 6.28318
```