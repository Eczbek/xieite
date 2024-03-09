# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line<Number>](../../../../line.md)\:\:Line
Defined in header [<xieite/geometry/line.hpp>](../../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Line<Number>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Line(xieite::geometry::Point<Number> start, xieite::geometry::Point<Number> end) noexcept;
```
#### 2)
```cpp
constexpr Line(xieite::geometry::Point<Number> start, std::conditional_t<std::floating_point<Number>, Number, double> angle) noexcept;
```

&nbsp;

## [Example](../../../../line.md)
