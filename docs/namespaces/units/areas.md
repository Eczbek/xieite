# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\: \(areas\)
Defined in header [<xieite/units/areas.hpp>](../../../include/xieite/units/areas.hpp)

&nbsp;

## Description
A colletion of ratios of square meters to other area units.

&nbsp;

## Synopses
#### 1)
```cpp
using SquareNanometer = std::ratio<1, std::nano::den * std::nano::den>;
```
#### 2)
```cpp
using SquareMicrometer = std::ratio<1, std::micro::den * std::micro::den>;
```
#### 3)
```cpp
using SquareMillimeter = std::ratio<1, std::milli::den * std::milli::den>;
```
#### 4)
```cpp
using SquareCentimeter = std::ratio<1, std::centi::den * std::centi::den>;
```
#### 5)
```cpp
using SquareDecimeter = std::ratio<1, std::deci::den * std::deci::den>;
```
#### 6)
```cpp
using SquareMeter = std::ratio<1, 1>;
```
#### 7)
```cpp
using SquareDecameter = std::ratio<std::deca::num * std::deca::num, 1>;
```
#### 8)
```cpp
using SquareHectometer = std::ratio<std::hecto::num * std::hecto::num, 1>;
```
#### 9)
```cpp
using SquareKilometer = std::ratio<std::kilo::num * std::kilo::num, 1>;
```
#### 10)
```cpp
using SquareMegameter = std::ratio<std::mega::num * std::mega::num, 1>;
```
#### 11)
```cpp
using SquareGigameter = std::ratio<std::giga::num * std::giga::num, 1>;
```
#### 12)
```cpp
using SquareThou = std::ratio<xieite::units::Thou::num * xieite::units::Thou::num, xieite::units::Thou::den * xieite::units::Thou::den>;
```
#### 13)
```cpp
using SquareBarleycorn = std::ratio<xieite::units::Barleycorn::num * xieite::units::Barleycorn::num, xieite::units::Barleycorn::den * xieite::units::Barleycorn::den>;
```
#### 14)
```cpp
using SquareInch = std::ratio<xieite::units::Inch::num * xieite::units::Inch::num, xieite::units::Inch::den * xieite::units::Inch::den>;
```
#### 15)
```cpp
using SquareFoot = std::ratio<xieite::units::Foot::num * xieite::units::Foot::num, xieite::units::Foot::den * xieite::units::Foot::den>;
```
#### 16)
```cpp
using SquareYard = std::ratio<xieite::units::Yard::num * xieite::units::Yard::num, xieite::units::Yard::den * xieite::units::Yard::den>;
```
#### 17)
```cpp
using SquareChain = std::ratio<xieite::units::Chain::num * xieite::units::Chain::num, xieite::units::Chain::den * xieite::units::Chain::den>;
```
#### 18)
```cpp
using SquareFurlong = std::ratio<xieite::units::Furlong::num * xieite::units::Furlong::num, xieite::units::Furlong::den * xieite::units::Furlong::den>;
```
#### 19)
```cpp
using SquareMile = std::ratio<xieite::units::Mile::num * xieite::units::Mile::num, xieite::units::Mile::den * xieite::units::Mile::den>;
```
#### 20)
```cpp
using SquareLeague = std::ratio<xieite::units::League::num * xieite::units::League::num, xieite::units::League::den * xieite::units::League::den>;
```
#### 21)
```cpp
using SquareFathom = std::ratio<xieite::units::Fathom::num * xieite::units::Fathom::num, xieite::units::Fathom::den * xieite::units::Fathom::den>;
```
#### 22)
```cpp
using SquareCable = std::ratio<xieite::units::Cable::num * xieite::units::Cable::num, xieite::units::Cable::den * xieite::units::Cable::den>;
```
#### 23)
```cpp
using SquareNauticalMile = std::ratio<xieite::units::NauticalMile::num * xieite::units::NauticalMile::num, xieite::units::NauticalMile::den * xieite::units::NauticalMile::den>;
```
#### 24)
```cpp
using SquareLink = std::ratio<xieite::units::Link::num * xieite::units::Link::num, xieite::units::Link::den * xieite::units::Link::den>;
```
#### 25)
```cpp
using SquareRod = std::ratio<xieite::units::Rod::num * xieite::units::Rod::num, xieite::units::Rod::den * xieite::units::Rod::den>;
```
#### 26)
```cpp
using Perch = std::ratio<2529285264, 100000000>;
```
#### 27)
```cpp
using Rood = std::ratio<10117141056, 10000000>;
```
#### 28)
```cpp
using Acre = std::ratio<40468564224, 10000000>;
```
