# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getLength
Defined in header [<xieite/geometry/getLength.hpp>](../../include/xieite/geometry/getLength.hpp)

&nbsp;

## Description
Calculates the length of a linear shape.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr double getLength(const xieite::geometry::Segment& segment) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr double getLength(const LinearShape&) noexcept;
```

&nbsp;

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
