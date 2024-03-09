# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray<Number>](../../../ray.md)\:\:length
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Always returns infinity.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> length() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/ray.hpp"

int main() {
    std::println("{}", xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).length());
}
```
Possible output:
```
inf
```
