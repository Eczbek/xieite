# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon<Arithmetic>](../../../polygon.md)\:\:rectangle\(\)
Defined in fragment [xieite:geometry.Polygon](../../../../../../src/geometry/polygon.cpp)

&nbsp;

## Description
Creates a rectangle from two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr xieite::geometry::Polygon<Arithmetic> rectangle(xieite::geometry::Point<Arithmetic> start, xieite::geometry::Point<Arithmetic> end) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto polygon = xieite::geometry::Polygon<>::rectangle({ 0.0, 0.0 }, { 2.0, 2.0 });

    for (auto point : polygon.points) {
        std::println("({}, {})", point.x, point.y);
    }
}
```
Possible output:
```
(0, 0)
(0, 2)
(2, 2)
(2, 0)
```
