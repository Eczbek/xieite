# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon<Arithmetic>](../../../polygon.md)\:\:area\(\)
Defined in fragment [xieite:geometry.Polygon](../../../../../../src/geometry/polygon.cpp)

&nbsp;

## Description
Computes the area of a polygon.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double area() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto polygon = xieite::geometry::Polygon({
        { 0.0, 0.0 },
        { 2.0, 0.0 },
        { 2.0, 2.0 },
        { 0.0, 2.0 }
    });

    std::println("{}", polygon.area());
}
```
Possible output:
```
4
```
