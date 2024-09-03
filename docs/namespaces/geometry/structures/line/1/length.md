# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line<Arithmetic>](../../../line.md)\:\:length\(\)
Defined in fragment [xieite:geometry.Line](../../../../../../src/geometry/line.cpp)

&nbsp;

## Description
Always returns infinity.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double length() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 }).length());
}
```
Output:
```
inf
```
