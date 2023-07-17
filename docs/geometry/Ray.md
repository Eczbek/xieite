# [xieite](../xieite.md)::[geometry](../geometry.md)::Ray
Defined in header [<xieite/geometry/Ray.hpp>](../../include/xieite/geometry/Ray.hpp)

<br/>

A struct representing an infinite ray with one end

<br/><br/>

## Synopsis

<br/>

```cpp
struct Ray {
	xieite::geometry::Point start;
	xieite::geometry::Point end;

	constexpr Ray(xieite::geometry::Point, xieite::geometry::Point);

	constexpr Ray(xieite::geometry::Point, double);

	constexpr bool operator==(const xieite::geometry::Ray&) const;
};
```
### Public members
<pre><code>Ray/
|- start
|- end
|- <a href="./Ray/constructor.md">Ray</a>
`- <a href="./Ray/operatorEquals.md">operator==</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< xieite::geometry::containsPoint(xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }), { -1.0, -1.0 }) << '\n';
}
```
Output:
```
false
```
