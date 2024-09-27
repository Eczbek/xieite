# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Segment<Arithmetic>](../../../../segment.md)\:\:operator==\(\)
Defined in fragment [xieite:geometry.Segment](../../../../../../../src/geometry/segment.cpp)

&nbsp;

## Description
Compares two segments.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const Segment& left, const Segment& right) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto segment1 = xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 });
    auto segment2 = xieite::geometry::Segment({ 3.0, 4.0 }, { 0.0, 0.0 });

    std::println("{}", segment1 == segment2);
}
```
Output:
```
true
```
