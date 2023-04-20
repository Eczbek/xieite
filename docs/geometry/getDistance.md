# `xieite::geometry::getDistance`
Defined in header [`<xieite/geometry/getDistance.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/getDistance.hpp)

<br/>

Calculates the distance between two points.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr double getDistance(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
### Parameters
- `point1` - A `xieite::geometry::Point` copy
- `point2` - Also a `xieite::geometry::Point` copy
### Return value
- `double` - Distance between the points

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/getDistance.hpp>

int main() {
	std::cout << xieite::geometry::getDistance({ 0.0, 0.0 }, { 3.0, 4.0 }) << '\n';
}
```
Output:
```
5
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point.md)