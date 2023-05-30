# [xieite](../../README.md)::[geometry](../geometry.md)::Segment
Defined in header [<xieite/geometry/Segment.hpp>](../../include/xieite/geometry/Segment.hpp)

<br/>

A struct representing a finite line segment

<br/><br/>

## Synopsis

<br/>

```cpp
struct Segment {
	xieite::geometry::Point start;
	xieite::geometry::Point end;

	constexpr Segment(xieite::geometry::Point, xieite::geometry::Point);

	constexpr bool operator==(const xieite::geometry::Segment&) const;
};
```
### Public members
<pre><code>Segment/
|- start
|- end
|- <a href="./Segment/constructor.md">Segment</a>
`- <a href="./Segment/operatorEquals.md">operator==</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>

int main() {
	std::cout << xieite::geometry::getLength(xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 })) << '\n';
}
```
Output:
```
5
```
