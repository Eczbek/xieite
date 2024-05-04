# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line<Arithmetic_>](../../../line.md)\:\:slope\(\)
Defined in header [<xieite/geometry/line.hpp>](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Computes the slope of a line.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double slope() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"

int main() {
    std::println("{}", xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).slope());
}
```
Possible output:
```
1
```
