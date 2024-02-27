# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedSet<Key, size, Hash, KeyComparator, Allocator>](../../../../fixed_set.md)\:\:contains
Defined in header [<xieite/containers/fixed_set.hpp>](../../../../../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

Checks if the set contains a key.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<Key> KeyReference>
[[nodiscard]] constexpr bool contains(KeyReference&& key) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/fixed_set.hpp"

int main() {
    xieite::containers::FixedSet<int, 3> set = {
        0,
        -17,
        418
    };

    std::println("{}", set.contains(0));
    std::println("{}", set.contains(999));
}
```
Output:
```
true
false
```
