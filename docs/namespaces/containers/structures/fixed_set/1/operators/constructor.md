# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedSet<Key, size, Hash, KeyComparator, Allocator>](../../../../fixed_set.md)\:\:FixedSet\(\)
Defined in header [<xieite/containers/fixed_set.hpp>](../../../../../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

Constructs a `xieite::containers::FixedSet`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Set() noexcept;
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<Key> Range>
constexpr Set(Range&& entries) noexcept;
```
#### 3)
```cpp
constexpr Set(std::initializer_list<Key> entries) noexcept;
```

&nbsp;

## Example
```cpp
#include <array>
#include <print>
#include "xieite/containers/fixed_set.hpp"

int main() {
    using FixedSet = xieite::containers::FixedSet<int, 3>;

    FixedSet foo;
    FixedSet bar = foo;

    std::array<std::pair<int, double>, 3> data {
        { 1, 2.71828 },
        { 2, 3.14159 },
        { 3, 6.28318 }
    };
    FixedSet baz = FixedSet(data);

    FixedSet qux = {
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
