# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line<Arithmetic>](../../../line.md)\:\:slope\(\)
Defined in fragment [xieite:geometry.Line](../../../../../../src/geometry/line.cpp)

&nbsp;

## Description
Computes the slope of a line.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double slope() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).slope());
}
```
Possible output:
```
1
```
