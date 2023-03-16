# xieite::geometry::Ray
Defined in header `<xieite/geometry/Ray.hpp>`

<br/>

A struct representing an infinite ray with one end, which is the member object `start`. Extends `xieite::geometry::LineLike`.

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
constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept;
```
```cpp
constexpr Ray(const xieite::geometry::Point start, const double angle) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Ray& other) const noexcept;
```
(`operator!=` is defined implicitly)

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
#include <xieite/geometry/Ray.hpp>

int main() {
	xieite::geometry::Ray ray({ 0.0, 0.0 }, { 1.0, 1.0 });
	std::cout << std::boolalpha
		<< xieite::geometry::containsPoint(ray, { -1.0, -1.0 }) << '\n';
}
```
Output:
```
false
```
