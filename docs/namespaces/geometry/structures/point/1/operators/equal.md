# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Point<Arithmetic>](../../../../point.md)\:\:operator==\(\)
Defined in fragment [xieite:geometry.Point](../../../../../../../src/geometry/point.cpp)

&nbsp;

## Description
Compares two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(xieite::geometry::Point<Arithmetic> point1, xieite::geometry::Point<Arithmetic> point2) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::units;

    auto point1 = xieite::geometry::Point(1.0, 0.0);

    auto point2 = xieite::geometry::Point(0.0, 1.0);

    std::println("{}", xieite::geometry::rotate(point1, 90_degrees) == point2);
}
```
Output:
```
true
```
