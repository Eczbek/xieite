# xieite::geometry::getLength
Defined in header `<xieite/geometry/getLength.hpp>`

<br/>

Calculates the length of a line-like.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr double getLength(const xieite::geometry::Line&) noexcept;
```
```cpp
[[nodiscard]]
constexpr double getLength(const xieite::geometry::Ray&) noexcept;
```
```cpp
[[nodiscard]]
constexpr double getLength(const xieite::geometry::Segment& segment) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>

int main() {
	const xieite::geometry::Segment segment({ 0, 0 }, { 3, 4 });
	std::cout << xieite::geometry::getLength(segment) << '\n';
}
```
Output:
```
5
```
