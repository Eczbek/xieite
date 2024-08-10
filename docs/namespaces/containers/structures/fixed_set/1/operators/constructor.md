# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedSet<Key_, size_, Hash_, KeyComparator,_ Allocator_>](../../../../fixed_set.md)\:\:FixedSet\<\>\(\)
Defined in header [<xieite/containers/fixed_set.hpp>](../../../../../../../include/xieite/containers/fixed_set.hpp)

&nbsp;

## Description
Constructs a `xieite::containers::FixedSet`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr FixedSet() noexcept;
```
#### 2)
```cpp
template<xieite::concepts::RangeOf<Key_> Range_>
explicit(false) constexpr FixedSet(Range_&& entries) noexcept;
```
#### 3)
```cpp
explicit(false) constexpr FixedSet(std::initializer_list<Key_> entries) noexcept;
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
