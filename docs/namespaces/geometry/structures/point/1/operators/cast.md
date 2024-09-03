# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Point<Arithmetic>](../../../../point.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:geometry.Point](../../../../../../../src/geometry/point.cpp)

&nbsp;

## Description
Casts one point type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic>
[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Point<OtherArithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto point1 = xieite::geometry::Point<double>(3.0, 4.0);

    xieite::geometry::Point<float> point2 = point1;

    std::println("({}, {})", point2.x, point2.y);
}
```
Output:
```
(3, 4)
```
