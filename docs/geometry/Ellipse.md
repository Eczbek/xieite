# xieite::geometry::Ellipse
Defined in header `<xieite/geometry/Ellipse.hpp>`

<br/>

An struct representing an ellipse.

<br/><br/>

## Member objects
```cpp
xieite::geometry::Point center;
```
```cpp
xieite::geometry::Point radii;
```
```cpp
double rotation;
```

## Constructors
```cpp
constexpr Ellipse(xieite::geometry::Point center, xieite::geometry::Point radii, double rotation = 0.0) noexcept;
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
#include <iostream>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout << xieite::geometry::getArea(xieite::geometry::Ellipse({ 0.0, 0.0 }, { 1.0, 2.0 })) << '\n';
}
```
Output:
```
6.28319
```
