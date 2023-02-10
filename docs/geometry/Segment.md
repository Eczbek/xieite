# xieite::geometry::Segment
Declared in `<xieite/geometry/Segment.hpp>`

<br/>

A line segment.

<br/><br/>

## Member objects inherited from `xieite::geometry::AbstractLine`
```cpp
xieite::geometry::Point start;
```
```cpp
xieite::geometry::Point end;
```

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


<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>

int main() {
	xieite::geometry::Segment segment({ 0, 0 }, { 3, 4 });
	std::cout << xieite::geometry::getLength(segment) << '\n';
}
```
Output:
```
5
```
