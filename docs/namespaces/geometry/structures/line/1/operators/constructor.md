# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Line<Arithmetic>](../../../../line.md)\:\:Line\(\)
Defined in fragment [xieite:geometry.Line](../../../../../../../src/geometry/line.cpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Line<Arithmetic>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Line(xieite::geometry::Point<Arithmetic> start, xieite::geometry::Point<Arithmetic> end) noexcept;
```
#### 2)
```cpp
constexpr Line(xieite::geometry::Point<Arithmetic> start, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle) noexcept;
```

&nbsp;

## [Example](../../../../line.md)
