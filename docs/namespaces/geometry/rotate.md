# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:rotate\<\>\(\)
Defined in header [<xieite/geometry/rotate.hpp>](../../../include/xieite/geometry/rotate.hpp)

&nbsp;

## Description
Rotates shapes a specific angle around any pivot, clockwise.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> rotate(xieite::geometry::Point<Arithmetic_> point, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle, xieite::geometry::Point<Arithmetic_> pivot = xieite::geometry::Point<Arithmetic_>()) noexcept;
```
#### 2)
```cpp
template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape>
[[nodiscard]] constexpr LinearShape rotate(const LinearShape& linearShape, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle, xieite::geometry::Point<Arithmetic_> pivot = xieite::geometry::Point<Arithmetic_>()) noexcept;
```
#### 3)
```cpp
template<typename Arithmetic_ = double>
[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> rotate(xieite::geometry::Polygon<Arithmetic_> polygon, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle, xieite::geometry::Point<Arithmetic_> pivot = xieite::geometry::Point<Arithmetic_>()) noexcept;
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
