# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key_, Value_, size_, Hash_, KeyComparator_, Allocator_>](../../../../fixed_map.md)\:\:contains\<\>\(\)
Defined in header [<xieite/containers/fixed_map.hpp>](../../../../../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
Checks if the map contains a key.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self_, std::convertible_to<Key_> KeyReference_>
[[nodiscard]] constexpr bool contains(this Self_&&, KeyReference_&& key) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/fixed_map.hpp"

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
