# [xieite](../../../../xieite.md)\:\:[units](../../../units.md)\:\:[literals](../literals.md)\:\: \(lengths\)
Defined in header [<xieite/literals/lengths.hpp>](../../../include/xieite/literals/lengths.hpp)

&nbsp;

## Description
A colletion of literals for length units.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr double operator""_twip(const long double value) noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr double operator""_thou(const long double value) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr double operator""_barleycorn(const long double value) noexcept;
```
#### 4)
```cpp
[[nodiscard]] constexpr double operator""_inch(const long double value) noexcept;
```
#### 5)
```cpp
[[nodiscard]] constexpr double operator""_foot(const long double value) noexcept;
```
#### 6)
```cpp
[[nodiscard]] constexpr double operator""_yard(const long double value) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr double operator""_chain(const long double value) noexcept;
```
#### 8)
```cpp
[[nodiscard]] constexpr double operator""_furlong(const long double value) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr double operator""_mile(const long double value) noexcept;
```
#### 10)
```cpp
[[nodiscard]] constexpr double operator""_league(const long double value) noexcept;
```
#### 11)
```cpp
[[nodiscard]] constexpr double operator""_fathom(const long double value) noexcept;
```
#### 12)
```cpp
[[nodiscard]] constexpr double operator""_cable(const long double value) noexcept;
```
#### 13)
```cpp
[[nodiscard]] constexpr double operator""_nauticalMile(const long double value) noexcept;
```
#### 14)
```cpp
[[nodiscard]] constexpr double operator""_link(const long double value) noexcept;
```
#### 15)
```cpp
[[nodiscard]] constexpr double operator""_rod(const long double value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/units/literals/lengths.hpp>

int main() {
    using namespace xieite::units::literals;

    std::cout << "One mile is " << 1.0_miles << " meters.\n";
}
```
Output:
```
One mile is 1609.34 meters.
```
