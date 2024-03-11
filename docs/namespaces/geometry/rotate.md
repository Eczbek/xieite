# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:rotate\(\)
Defined in header [<xieite/geometry/rotate.hpp>](../../../include/xieite/geometry/rotate.hpp)

&nbsp;

## Description
Rotates shapes a specific angle around any pivot, clockwise.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr xieite::geometry::Point<Number> rotate(xieite::geometry::Point<Number> point, std::conditional_t<std::floating_point<Number>, Number, double> angle, xieite::geometry::Point<Number> pivot = xieite::geometry::Point<Number>()) noexcept;
```
#### 2)
```cpp
template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
[[nodiscard]] constexpr LinearShape rotate(const LinearShape& linearShape, std::conditional_t<std::floating_point<Number>, Number, double> angle, xieite::geometry::Point<Number> pivot = xieite::geometry::Point<Number>()) noexcept;
```
#### 3)
```cpp
template<typename Number = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Number> rotate(xieite::geometry::Polygon<Number> polygon, std::conditional_t<std::floating_point<Number>, Number, double> angle, xieite::geometry::Point<Number> pivot = xieite::geometry::Point<Number>()) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/line.hpp"
#include "xieite/geometry/rotate.hpp"
#include "xieite/literals/units.hpp"

int main() {
    using namespace xieite::literals::units;

    auto line1 = xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 });

    auto line2 = xieite::geometry::rotate(line1, 90_degrees);

    std::println("{}", line1.slope());
    std::println("{}", line2.slope());
}
```
Possible output:
```
1
-1
```
