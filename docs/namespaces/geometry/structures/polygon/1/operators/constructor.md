# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Polygon<Arithmetic>](../../../../polygon.md)\:\:Polygon\(\)
Defined in fragment [xieite:geometry.Polygon](../../../../../../../src/geometry/polygon.cpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Polygon<Arithmetic>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range PointRange = std::vector<xieite::geometry::Point<Arithmetic>>>
requires(std::convertible_to<std::ranges::range_value_t<PointRange>, xieite::geometry::Point<Arithmetic>>)
explicit constexpr Polygon(PointRange&& points) noexcept;
```

&nbsp;

## [Example](../../../../polygon.md#Example)
