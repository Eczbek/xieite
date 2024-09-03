# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\:convert\<\>\(\)
Defined in fragment [xieite:units.convert](../../../src/units/convert.cpp)

&nbsp;

## Description
Converts one unit type to another.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result convert(Arithmetic value, xieite::units::Angle source, xieite::units::Angle target) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result convert(Arithmetic value, xieite::units::Area source, xieite::units::Area target) noexcept;
```
#### 3)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result convert(Arithmetic value, xieite::units::Length source, xieite::units::Length target) noexcept;
```
#### 4)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result convert(Arithmetic value, xieite::units::Temperature source, xieite::units::Temperature target) noexcept;
```
#### 5)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
[[nodiscard]] constexpr Result convert(Arithmetic value, xieite::units::Volume source, xieite::units::Volume target) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::units;

    std::println("{}", xieite::units::convert(90, xieite::units::Angle::Degree, xieite::units::Angle::Radian));
    std::println("{}", xieite::units::convert(4000, xieite::units::Length::Foot, xieite::units::Length::Kilometre));
    std::println("{}", xieite::units::convert(2, xieite::units::Area::SquareInch, xieite::units::Area::Hectare));
    std::println("{}", xieite::units::convert(3, xieite::units::Volume::Gallon, xieite::units::Volume::Millilitre));
    std::println("{}", xieite::units::convert(20, xieite::units::Temperature::Celsius, xieite::units::Temperature::Fahrenheit));
}
```
Possible output:
```
1.5707963267948966
1.2192
0.31000062000124
1.1356236e-08
68
```
