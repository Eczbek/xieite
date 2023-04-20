# `xieite::geometry::Line::operator==`
Defined in header [`<xieite/geometry/Line.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/Line.hpp)

<br/>

Compares two lines to each other.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Line& line) const noexcept;
```
### Parameters
- `line` - A `xieite::geometry::Line` constant reference
### Return value
- `bool` - Whether or not the compared shapes are equal

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
	xieite::geometry::Line line1({ 0, 0 }, { 1, 1 });
	xieite::geometry::Line line2({ 0, 0 }, xieite::math::toRadians(45.0));

	std::cout << std::boolalpha << (line1 == line2) << '\n';
}
```
Output:
```
true
```

<br/><br/>

## See also
- [`xieite::geometry::Line`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Line.md)
