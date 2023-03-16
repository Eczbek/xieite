# xieite::geometry::Segment
Defined in header `<xieite/geometry/Segment.hpp>`

<br/>

A struct representing a finite line segment. Extends `xieite::geometry::LineLike`.

<br/><br/>

## Member objects inherited from `xieite::geometry::LineLike`
```cpp
xieite::geometry::Point start;
```
```cpp
xieite::geometry::Point end;
```

## Constructors
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
	xieite::geometry::Segment segment({ 0.0, 0.0 }, { 3.0, 4.0 });
	std::cout << xieite::geometry::getLength(segment) << '\n';
}
```
Output:
```
5
```
