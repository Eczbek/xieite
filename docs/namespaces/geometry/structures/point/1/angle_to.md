# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point<Arithmetic>](../../../point.md)\:\:angleTo\(\)
Defined in fragment [xieite:geometry.Point](../../../../../../src/geometry/point.cpp)

&nbsp;

## Description
Computes the angle between two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angleTo(Point point) const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Point(0.0, 0.0).angleTo({ 1.0, 1.0 }));
}
```
Possible output:
```
0.7853981633974483
```
