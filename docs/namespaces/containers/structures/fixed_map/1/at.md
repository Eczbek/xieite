# [xieite](../../../../../xieite.md)\:\:[containers](../../../../../containers.md)\:\:[FixedMap<Key_, Value_, size_, Hash_, KeyComparator_, Allocator_>](../../../fixed_map.md)\:\:at\<\>\(\)
Defined in header [<xieite/containers/fixed_map.hpp>](../../../../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
Accesses a value by its key, if it exists.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self_, std::convertible_to<Key_> KeyReference_>
[[nodiscard]] constexpr std::optional<std::reference_wrapper<xieite::types::MaybeConstant<Value_, std::is_const_v<Self_>>>> at(this Self_&&, KeyReference_&& key) noexcept;
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
        std::println("{}: {}", i, map.at(i).value());
    }
}
```
Output:
```
1: 2.71828
2: 3.14159
2: 6.28318
```