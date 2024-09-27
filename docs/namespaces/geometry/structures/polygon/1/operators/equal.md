# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Polygon<Arithmetic>](../../../../polygon.md)\:\:operator==\(\)
Defined in fragment [xieite:geometry.Polygon](../../../../../../../src/geometry/polygon.cpp)

&nbsp;

## Description
Compares two polygons.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const Polygon& left, const Polygon& right) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto polygon1 = xieite::geometry::Polygon({
        { 0.0, 0.0 },
        { 2.0, 0.0 },
        { 2.0, 2.0 },
        { 0.0, 2.0 }
    });

    auto polygon2 = xieite::geometry::Polygon({
        { 0.0, 2.0 },
        { 2.0, 2.0 },
        { 2.0, 0.0 },
        { 0.0, 0.0 }
    });

    std::println("{}", polygon1 == polygon2);
}
```
Output:
```
true
```
