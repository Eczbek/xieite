# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line<Arithmetic_>](../../../../line.md)\:\:Line\(\)
Defined in header [<xieite/geometry/line.hpp>](../../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Line<Arithmetic_>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Line(xieite::geometry::Point<Arithmetic_> start, xieite::geometry::Point<Arithmetic_> end) noexcept;
```
#### 2)
```cpp
constexpr Line(xieite::geometry::Point<Arithmetic_> start, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle) noexcept;
```

&nbsp;

## [Example](../../../../line.md)
