# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray<Arithmetic>](../../../ray.md)\:\:angle\(\)
Defined in fragment [xieite:geometry.Ray](../../../../../../src/geometry/ray.cpp)

&nbsp;

## Description
Computes the angle of a ray in radians.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).angle());
}
```
Possible output:
```
0.7853981633974483
```
