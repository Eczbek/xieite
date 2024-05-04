# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray<Arithmetic_>](../../../../ray.md)\:\:operator typename\<\>\(\)
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Casts one ray type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic_>
[[nodiscard]] constexpr operator xieite::geometry::Ray<OtherArithmetic_>() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/ray.hpp"

int main() {
    auto ray1 = xieite::geometry::Ray<double>({ 0.0, 0.0 }, { 1.0, 1.0 });

    xieite::geometry::Ray<float> ray2 = ray1;

    std::println("{}", ray1.slope() == ray2.slope());
}
```
Output:
```
true
```
