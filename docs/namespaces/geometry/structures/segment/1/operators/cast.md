# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Segment<Arithmetic>](../../../../segment.md)\:\:operator typename\<\>\(\)
Defined in fragment [xieite:geometry.Segment](../../../../../../../src/geometry/segment.cpp)

&nbsp;

## Description
Casts one segment type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename OtherArithmetic>
[[nodiscard]] explicit(false) constexpr operator Segment<OtherArithmetic>() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto segment1 = xieite::geometry::Segment<double>({ 0.0, 0.0 }, { 3.0, 4.0 });
    float slope1 = static_cast<float>(segment1.slope());

    xieite::geometry::Segment<float> segment2 = segment1;
    float slope2 = segment2.slope();

    std::println("{}", xieite::math::almostEqualSlope(slope1, slope2));
}
```
Possible output:
```
true
```
