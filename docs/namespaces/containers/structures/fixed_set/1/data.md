# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedSet<Key_, size_, Hash_, KeyComparator,_ Allocator_>](../../../../fixed_set.md)\:\:data\(\)
Defined in header [<xieite/containers/fixed_set.hpp>](../../../../../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

## Description
Returns the underlying data. Its order is not specified.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr const std::array<Key_, size_>& data() const noexcept;
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

    for (int item : set.data()) {
        std::println("{}", item);
    }
}
```
Possible output:
```
0
-17
418
```
