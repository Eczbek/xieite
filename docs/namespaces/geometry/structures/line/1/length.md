# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line<Arithmetic_>](../../../line.md)\:\:length\(\)
Defined in header [<xieite/geometry/line.hpp>](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Always returns infinity.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double length() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"

int main() {
    std::println("{}", xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).length());
}
```
Output:
```
inf
```
