# xieite::geometry::Circle
Declared in `<xieite/geometry/Circle.hpp>`

<br/>

A basic circle.

<br/><br/>

## Member objects
```cpp
xieite::geometry::Point center;
```
```cpp
long double radius;
```

## Constructor
```cpp
constexpr Circle(const xieite::geometry::Point center, const long double radius) noexcept;
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
	const xieite::geometry::Circle circle({ 0, 0 }, 3);
	std::cout << xieite::geometry::getArea(circle) << '\n';
}
```
Output:
```
28.2743
```
