# xieite::geometry::Segment
Declared in `<xieite/geometry/Segment.hpp>`

<br/>

A 2D line segment, derived from `xieite::geometry::Line`.

<br/><br/>

## Constructor
```cpp
constexpr Segment(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Segment& other) const noexcept;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
[[nodiscard]]
constexpr bool contains(const xieite::geometry::Point point) const noexcept override;
```
```cpp
[[nodiscard]]
constexpr double length() const noexcept override;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Segment.hpp>

int main() {
	std::cout << xieite::geometry::Segment({ 0, 0 }, { 3, 4 }).length() << '\n';
}
```
Output:
```
5
```
