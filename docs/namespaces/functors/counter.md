# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:counter
Defined in header [<xieite/functors/counter.hpp>](../../../include/xieite/functors/counter.hpp)

&nbsp;

## Description
A compile-time counter thingamabob. Technically not IFNDR but causes wonky behavior if used in template constraints.

&nbsp;

## Synopsis
#### 1)
```cpp
template<auto tag = [] {}>
[[nodiscard]] constexpr std::size_t counter() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/counter.hpp"

int main() {
    static constexpr std::size_t x = xieite::functors::counter();
    static constexpr std::size_t y = xieite::functors::counter();
    static constexpr std::size_t z = xieite::functors::counter();

    std::println("{} {} {}", x, y, z);
}
```
Output:
```
0 1 2
```
