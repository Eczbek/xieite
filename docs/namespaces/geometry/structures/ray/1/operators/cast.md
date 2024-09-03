# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray<Arithmetic>](../../../../ray.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:geometry.Ray](../../../../../../../src/geometry/ray.cpp)

&nbsp;

## Description
Casts one ray type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic>
[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Ray<OtherArithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto ray1 = xieite::geometry::Ray<double>({ 0.0, 0.0 }, { 1.0, 1.0 });
    float slope1 = static_cast<float>(ray1.slope());

    xieite::geometry::Ray<float> ray2 = ray1;
    float slope2 = ray2.slope();

    std::println("{}", xieite::math::almostEqualSlope(slope1, slope2));
}
```
Possible output:
```
true
```
