# xieite::geometry::Ray
Declared in `<xieite/geometry/Ray.hpp>`

<br/>

A 2D infinite ray, derived from `xieite::geometry::Line`.

<br/><br/>

## Constructors
```cpp
constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point intersection) noexcept;
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

## Other methods
```cpp
[[nodiscard]]
constexpr bool contains(const xieite::geometry::Point point) const noexcept override;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>

int main() {
	std::cout << std::boolalpha
		<< xieite::geometry::Ray({ 0, 0 }, { 1, 1 }).contains({ -1, -1 }) << '\n';
}
```
Output:
```
false
```
