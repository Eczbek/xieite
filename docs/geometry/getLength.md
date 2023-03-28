# xieite::geometry::getLength
Defined in header `<xieite/geometry/getLength.hpp>`

<br/>

Calculates the length of a line-like.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr double getLength(const std::derived_from<xieite::geometry::LineLike> auto&) noexcept;
```
```cpp
[[nodiscard]]
constexpr double getLength(const xieite::geometry::Segment& segment) noexcept;
```

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
