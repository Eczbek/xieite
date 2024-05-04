# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key_, Value_, size_, Hash_, KeyComparator_, Allocator_>](../../../../fixed_map.md)\:\:data\(\)
Defined in header [<xieite/containers/fixed_map.hpp>](../../../../../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
Returns the underlying data. Its order is not specified.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr const std::array<std::pair<Key_, Value_>, size_>& data() const noexcept;
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
