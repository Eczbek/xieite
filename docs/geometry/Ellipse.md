# xieite::geometry::Ellipse
Declared in `<xieite/geometry/Ellipse.hpp>`

<br/>

An ellipse.

<br/><br/>

## Member objects
```cpp
xieite::geometry::Point center;
```
```cpp
xieite::geometry::Point radii;
```
```cpp
long double rotation;
```

## Constructor
```cpp
constexpr Ellipse(const xieite::geometry::Point center, const xieite::geometry::Point radii, const long double rotation = 0) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Ellipse& other) const noexcept;
```
(`operator!=` is defined implicitly)

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	const xieite::geometry::Ellipse ellipse({ 0, 0 }, { 1, 2 });
	std::cout << xieite::geometry::getArea(ellipse) << '\n';
}
```
Output:
```
6.28319
```
