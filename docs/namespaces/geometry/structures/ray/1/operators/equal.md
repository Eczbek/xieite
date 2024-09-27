# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray<Arithmetic>](../../../../ray.md)\:\:operator==\(\)
Defined in fragment [xieite:geometry.Ray](../../../../../../../src/geometry/ray.cpp)

&nbsp;

## Description
Compares two rays.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const Ray& left, const Ray& right) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
