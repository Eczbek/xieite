# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point<Arithmetic>](../../../point.md)\:\:slopeTo\(\)
Defined in fragment [xieite:geometry.Point](../../../../../../src/geometry/point.cpp)

&nbsp;

## Description
Computes the slope between two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slopeTo(xieite::geometry::Point<Arithmetic> point) const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Point(0.0, 0.0).slopeTo({ 1.0, 1.0 }));
}
```
Possible output:
```
1
```
