# [xieite](../xieite.md)::[geometry](../geometry.md)::getLength
Defined in header [<xieite/geometry/getLength.hpp>](../../include/xieite/geometry/getLength.hpp)

<br/>

Calculates the length of a linear shape

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr double getLength(const xieite::geometry::Segment& segment) noexcept;
```
### Parameters
- `segment` - A `xieite::geometry::Segment` constant reference
### Return value
- A `double` - The distance between the segment's ends

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr double getLength(const LinearShape&) noexcept;
```
### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- An unnamed constant `LinearShape` reference
### Return value
- A `double` - Always infinity

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
