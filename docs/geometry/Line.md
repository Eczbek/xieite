# xieite::geometry::Line
Defined in header `<xieite/geometry/Line.hpp>`

<br/>

An struct representing an infinite line. Extends `xieite::geometry::LineLike`.

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
constexpr Line(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
```cpp
constexpr Line(xieite::geometry::Point start, double angle) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Line& other) const noexcept;
```
(`operator!=` is defined implicitly)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
	std::cout << xieite::geometry::getAngle(xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 })) << '\n';
}
```
Output:
```
0.785398
```
