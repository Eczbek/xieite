# xieite::geometry::Line
Declared in `<xieite/geometry/Line.hpp>`

<br/>

A 2D infinite line.

<br/><br/>

## Member objects
```cpp
xieite::geometry::Point start
```
```cpp
xieite::geometry::Point end
```

## Constructors
```cpp
constexpr Line(const xieite::geometry::Point intersection1, const xieite::geometry::Point intersection2) noexcept;
```
```cpp
constexpr Line(const xieite::geometry::Point intersection, const double angle) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Line& other) const noexcept;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
[[nodiscard]]
constexpr double angle() const noexcept;
```
```cpp
[[nodiscard]]
virtual constexpr bool contains(const xieite::geometry::Point point) const noexcept;
```
```cpp
[[nodiscard]]
constexpr std::optional<xieite::geometry::Point> intersection(const xieite::geometry::Line& other) const noexcept;
```
```cpp
[[nodiscard]]
virtual constexpr double length() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Line rotate(const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept;
```
```cpp
[[nodiscard]]
constexpr double slope() const noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>

int main() {
	std::cout << xieite::geometry::Line({ 0, 0 }, { 1, 1 }).angle() << '\n';
}
```
Output:
```
0.785398
```
