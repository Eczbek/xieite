# xieite::geometry::Ray
Declared in `<xieite/geometry/Ray.hpp>`

<br/>

An infinite ray with one end.

<br/><br/>

## Member objects inherited from `xieite::geometry::AbstractLine`
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
constexpr Ray(const xieite::geometry::Point start, const long double angle) noexcept;
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
	xieite::geometry::Ray ray({ 0, 0 }, { 1, 1 });
	std::cout << std::boolalpha
		<< xieite::geometry::containsPoint(ray, { -1, -1 }) << '\n';
}
```
Output:
```
false
```
