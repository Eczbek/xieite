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
constexpr Segment(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
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
#include <iostream>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>

int main() {
	std::cout << xieite::geometry::getLength(xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 })) << '\n';
}
```
Output:
```
5
```
