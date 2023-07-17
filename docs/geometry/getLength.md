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
- `double` - The distance between the segment's ends

<br/><br/>

```cpp
[[nodiscard]]
constexpr double getLength(const xieite::concepts::LinearShape auto&) noexcept;
```
### Parameters
- An unnamed auto constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `double` - Always infinity

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
