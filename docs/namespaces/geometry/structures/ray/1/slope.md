# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Ray<Arithmetic>](../../../ray.md)\:\:slope\(\)
Defined in fragment [xieite:geometry.Ray](../../../../../../src/geometry/ray.cpp)

&nbsp;

## Description
Computes the slope of a ray.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> slope() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }).slope());
}
```
Possible output:
```
1
```
