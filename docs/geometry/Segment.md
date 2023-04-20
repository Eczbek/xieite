# `xieite::geometry::Segment`
Defined in header [`<xieite/geometry/Segment.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/Segment.hpp)

<br/>

A struct representing a finite line segment.

<br/><br/>

## Synopsis

<br/>

### Member objects
```cpp
xieite::geometry::Point start;
```
```cpp
xieite::geometry::Point end;
```

<br/>

### Member functions
- [`Segment`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Segment/constructor.hpp)
- [`operator==`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Segment/operatorEquals.hpp)

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

<br/><br/>

## See also
- [`xieite::geometry::Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point.md)
