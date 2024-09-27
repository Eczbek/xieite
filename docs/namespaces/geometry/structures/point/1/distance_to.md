# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point<Arithmetic>](../../../point.md)\:\:distanceTo\(\)
Defined in fragment [xieite:geometry.Point](../../../../../../src/geometry/point.cpp)

&nbsp;

## Description
Computes the distance between two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> distanceTo(Point point) const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Point(0.0, 0.0).distanceTo({ 1.0, 1.0 }));
}
```
Possible output:
```
1.4142135623730951
```
