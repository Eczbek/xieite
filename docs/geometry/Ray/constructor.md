# `xieite::geometry::Ray::Ray`
Defined in header [`<xieite/geometry/Ray.hpp>`](../../../include/xieite/geometry/Ray.hpp)

<br/>

Constructs a `xieite::geometry::Ray`.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Ray(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, the start of the ray
- `end` - A `xieite::geometry::Point` copy, an intersection through which the infinite ray passes

<br/>

```cpp
constexpr Ray(xieite::geometry::Point start, double angle) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, the start of the ray
- `angle` - A `double` copy, the ray's angle

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
	std::cout << std::boolalpha
		<< xieite::geometry::containsPoint(xieite::geometry::Ray({ 0, 0 }, { 1, 1 }), { -1, -1 }) << '\n';
}
```
Output:
```
false
```

<br/><br/>

## See also
- [`xieite::geometry::Ray`](../../../docs/geometry/Ray.md)
- [`xieite::geometry::Point`](../../../docs/geometry/Point.md)
