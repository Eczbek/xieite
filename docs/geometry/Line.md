# xieite::geometry::Line
Declared in `<xieite/geometry/Line.hpp>`

<br/>

An infinite line.

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
constexpr Line(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept;
```
```cpp
constexpr Line(const xieite::geometry::Point start, const long double angle) noexcept;
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
#include <iostream> // std::cout
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
	const xieite::geometry::Line line({ 0, 0 }, { 1, 1 });
	std::cout << xieite::geometry::getAngle(line) << '\n';
}
```
Output:
```
0.785398
```
