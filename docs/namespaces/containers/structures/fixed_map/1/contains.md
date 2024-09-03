# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key, Value, size, Hash, KeyComparator, Allocator>](../../../../fixed_map.md)\:\:contains\<\>\(\)
Defined in fragment [xieite:containers.FixedMap](../../../../../../../src/containers/fixed_map.cpp)

&nbsp;

## Description
Checks if the map contains a key.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self, std::convertible_to<Key> KeyReference>
[[nodiscard]] constexpr bool contains(this Self&&, KeyReference&& key) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::containers::FixedMap<int, double, 3> map = {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };

    std::println("{}", map.contains(1));
    std::println("{}", map.contains(999));
}
```
Output:
```
true
false
```
