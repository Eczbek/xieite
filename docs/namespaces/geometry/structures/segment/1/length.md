# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment<Arithmetic>](../../../segment.md)\:\:length\(\)
Defined in fragment [xieite:geometry.Segment](../../../../../../src/geometry/segment.cpp)

&nbsp;

## Description
Computes the distance between the start and end of a segment.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> length() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 }).length());
}
```
Possible output:
```
1.4142135623730951
```
