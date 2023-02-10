# xieite::geometry::getLength
Declared in `<xieite/geometry/getLength.hpp>`

<br/>

Calculates the length of a line.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr long double getLength(const xieite::geometry::Line&) noexcept;
```
```cpp
[[nodiscard]]
constexpr long double getLength(const xieite::geometry::Ray&) noexcept;
```
```cpp
[[nodiscard]]
constexpr long double getLength(const xieite::geometry::Segment& segment) noexcept;
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
