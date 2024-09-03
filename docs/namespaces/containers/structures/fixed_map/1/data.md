# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key, Value, size, Hash, KeyComparator, Allocator>](../../../../fixed_map.md)\:\:data\(\)
Defined in fragment [xieite:containers.FixedMap](../../../../../../../src/containers/fixed_map.cpp)

&nbsp;

## Description
Returns the underlying data. Its order is not specified.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr const std::array<std::pair<Key, Value>, size>& data() const noexcept;
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

    for (auto [key, value] : map.data()) {
        std::println("{}: {}", key, value);
    }
}
```
Possible output:
```
1: 2.71828
2: 3.14159
3: 6.28318
```
