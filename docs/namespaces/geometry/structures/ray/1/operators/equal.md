# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray<Arithmetic>](../../../../ray.md)\:\:operator==\(\)
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Compares two rays.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Ray<Arithmetic>& ray1, const xieite::geometry::Ray<Arithmetic>& ray2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/ray.hpp"
#include "xieite/literals/units.hpp"

int main() {
    using namespace xieite::literals::units;

    auto ray1 = xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 });
    auto ray2 = xieite::geometry::Ray({ 0.0, 0.0 }, 45_degrees);

    std::println("{}", ray1 == ray2);
}
```
Output:
```
true
```
