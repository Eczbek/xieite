# xieite::geometry::Circle
Defined in header `<xieite/geometry/Circle.hpp>`

<br/>

A struct representing a circle. The circle has no angle of rotation.

<br/><br/>

## Member objects
```cpp
xieite::geometry::Point center;
```
```cpp
double radius;
```

## Constructors
```cpp
constexpr Circle(xieite::geometry::Point center, double radius) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Circle& other) const noexcept;
```
(`operator!=` is defined implicitly)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout << xieite::geometry::getArea(xieite::geometry::Circle({ 0.0, 0.0 }, 3.0)) << '\n';
}
```
Output:
```
28.2743
```
