# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line<Arithmetic>](../../../line.md)\:\:angle\(\)
Defined in fragment [xieite:geometry.Line](../../../../../../src/geometry/line.cpp)

&nbsp;

## Description
Computes the angle of a line in radians.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double angle() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).angle());
}
```
Possible output:
```
0.7853981633974483
```
