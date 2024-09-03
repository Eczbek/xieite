# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray<Arithmetic>](../../../../ray.md)\:\:Ray\(\)
Defined in fragment [xieite:geometry.Ray](../../../../../../../src/geometry/ray.cpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Ray<Arithmetic>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Ray(xieite::geometry::Point<Arithmetic> start, xieite::geometry::Point<Arithmetic> end) noexcept;
```
#### 2)
```cpp
constexpr Ray(xieite::geometry::Point<Arithmetic> start, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle) noexcept;
```

&nbsp;

## [Example](../../../../ray.md#Example)

