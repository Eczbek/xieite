# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedMap<Key_, Value_, size_, Hash_, KeyComparator_, Allocator_>](../../../../fixed_map.md)\:\:FixedMap\<\>\(\)
Defined in header [<xieite/containers/fixed_map.hpp>](../../../../../../../include/xieite/containers/fixed_map.hpp)

&nbsp;

## Description
Constructs a `xieite::containers::FixedMap`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr FixedMap() noexcept;
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<std::pair<Key_, Value_>> Range_>
constexpr FixedMap(Range_&& entries) noexcept;
```
#### 3)
```cpp
constexpr FixedMap(std::initializer_list<std::pair<Key_, Value_>> entries) noexcept;
```

&nbsp;

## Example
```cpp
#include <array>
#include <print>
#include "xieite/containers/fixed_map.hpp"

int main() {
    using FixedMap = xieite::containers::FixedMap<int, double, 3>;

    FixedMap foo;
    FixedMap bar = foo;

    std::array<std::pair<int, double>, 3> data {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };
    FixedMap baz = FixedMap(data);

    FixedMap qux = {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };

    std::println("{}", baz[1]);
    std::println("{}", qux[2]);
}
```
Output:
```
3.14159
6.28318
```
