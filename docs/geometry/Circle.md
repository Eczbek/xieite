# xieite::geometry::Circle
Declared in `<xieite/geometry/Circle.hpp>`

<br/>

A 2D circle, derived from `xieite::geometry::Ellipse`.

<br/><br/>

## Constructor
```cpp
constexpr Circle(const xieite::geometry::Point center, const double radius) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Circle& other) const noexcept override;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
[[nodiscard]]
constexpr double area() const noexcept override;
```
```cpp
[[nodiscard]]
constexpr xieite::geometry::Polygon boundingBox() const noexcept override;
```
```cpp
[[nodiscard]]
constexpr bool contains(const xieite::geometry::Point point) const noexcept override;
```
```cpp
[[nodiscard]]
constexpr double perimeter() const noexcept override;
```

<br/><br/>


## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>

int main() {
	std::cout << xieite::geometry::Circle({ 0, 0 }, 3).area() << '\n';
}
```
Output:
```
28.2743
```
