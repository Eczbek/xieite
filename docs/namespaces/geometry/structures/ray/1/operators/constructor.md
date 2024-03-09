# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray<Number>](../../../../ray.md)\:\:Ray
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Ray<Number>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Ray(xieite::geometry::Point<Number> start, xieite::geometry::Point<Number> end) noexcept;
```
#### 2)
```cpp
constexpr Ray(xieite::geometry::Point<Number> start, std::conditional_t<std::floating_point<Number>, Number, double> angle) noexcept;
```

&nbsp;

## [Example](../../../../ray.md#Example)

