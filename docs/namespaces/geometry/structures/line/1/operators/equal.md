# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line<Arithmetic>](../../../../line.md)\:\:operator==\(\)
Defined in fragment [xieite:geometry.Line](../../../../../../../src/geometry/line.cpp)

&nbsp;

## Description
Compares two lines.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Line<Arithmetic>& line1, const xieite::geometry::Line<Arithmetic>& line2) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::units;

    auto line1 = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });
    auto line2 = xieite::geometry::Line({ 0.0, 0.0 }, 45_degrees);

    std::println("{}", line1 == line2);
}
```
Output:
```
true
```
