# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\:convert
Defined in header [<xieite/units/convert.hpp"](../../../include/xieite/units/convert.hpp)

&nbsp;

## Description
Converts one unit type to another.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> convert(Number value, xieite::units::Angle source, xieite::units::Angle target) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> convert(Number value, xieite::units::Area source, xieite::units::Area target) noexcept;
```
#### 3)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> convert(Number value, xieite::units::Length source, xieite::units::Length target) noexcept;
```
#### 4)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> convert(Number value, xieite::units::Temperature source, xieite::units::Temperature target) noexcept;
```
#### 5)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr std::common_type_t<double, Number> convert(Number value, xieite::units::Volume source, xieite::units::Volume target) noexcept;
```
