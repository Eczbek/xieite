# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Ray<Arithmetic_>](../../../../ray.md)\:\:Ray\(\)
Defined in header [<xieite/geometry/ray.hpp>](../../../../../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Ray<Arithmetic_>`.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr Ray(xieite::geometry::Point<Arithmetic_> start, xieite::geometry::Point<Arithmetic_> end) noexcept;
```
#### 2)
```cpp
constexpr Ray(xieite::geometry::Point<Arithmetic_> start, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle) noexcept;
```

&nbsp;

## [Example](../../../../ray.md#Example)

