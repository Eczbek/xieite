# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\: \(area\)
Defined in fragment [xieite:units.area](../../../src/units/area.cpp)

&nbsp;

## Description
A collection of type aliases for area units.

&nbsp;

## Synopsis
#### 1)
```cpp
using SquareQuectometre = xieite::units::Unit<"area", /* ... */>;
```
#### 2)
```cpp
using SquareRontometre = xieite::units::Unit<"area", /* ... */>;
```
#### 3)
```cpp
using SquareYoctometre = xieite::units::Unit<"area", /* ... */>;
```
#### 4)
```cpp
using SquareZeptometre = xieite::units::Unit<"area", /* ... */>;
```
#### 5)
```cpp
using SquareAttometre = xieite::units::Unit<"area", /* ... */>;
```
#### 6)
```cpp
using SquareFemtometre = xieite::units::Unit<"area", /* ... */>;
```
#### 7)
```cpp
using SquarePicometre = xieite::units::Unit<"area", /* ... */>;
```
#### 8)
```cpp
using SquareNanometre = xieite::units::Unit<"area", /* ... */>;
```
#### 9)
```cpp
using SquareMicrometre = xieite::units::Unit<"area", /* ... */>;
```
#### 10)
```cpp
using SquareMillimetre = xieite::units::Unit<"area", /* ... */>;
```
#### 11)
```cpp
using SquareCentimetre = xieite::units::Unit<"area", /* ... */>;
```
#### 12)
```cpp
using SquareDecimetre = xieite::units::Unit<"area", /* ... */>;
```
#### 13)
```cpp
using SquareMetre = xieite::units::Unit<"area", /* ... */>;
```
#### 14)
```cpp
using SquareDecametre = xieite::units::Unit<"area", /* ... */>;
```
#### 15)
```cpp
using SquareHectometre = xieite::units::Unit<"area", /* ... */>;
```
#### 16)
```cpp
using SquareKilometre = xieite::units::Unit<"area", /* ... */>;
```
#### 17)
```cpp
using SquareMegametre = xieite::units::Unit<"area", /* ... */>;
```
#### 18)
```cpp
using SquareGigametre = xieite::units::Unit<"area", /* ... */>;
```
#### 19)
```cpp
using SquareTerametre = xieite::units::Unit<"area", /* ... */>;
```
#### 20)
```cpp
using SquarePetametre = xieite::units::Unit<"area", /* ... */>;
```
#### 21)
```cpp
using SquareExametre = xieite::units::Unit<"area", /* ... */>;
```
#### 22)
```cpp
using SquareZettametre = xieite::units::Unit<"area", /* ... */>;
```
#### 23)
```cpp
using SquareYottametre = xieite::units::Unit<"area", /* ... */>;
```
#### 24)
```cpp
using SquareRonnametre = xieite::units::Unit<"area", /* ... */>;
```
#### 25)
```cpp
using SquareQuettametre = xieite::units::Unit<"area", /* ... */>;
```
#### 26)
```cpp
using SquareInch = xieite::units::Unit<"area", /* ... */>;
```
#### 27)
```cpp
using SquareFoot = xieite::units::Unit<"area", /* ... */>;
```
#### 28)
```cpp
using SquareYard = xieite::units::Unit<"area", /* ... */>;
```
#### 29)
```cpp
using SquareMile = xieite::units::Unit<"area", /* ... */>;
```
#### 30)
```cpp
using SquareRood = xieite::units::Unit<"area", /* ... */>;
```
#### 31)
```cpp
using Acre = xieite::units::Unit<"area", /* ... */>;
```
#### 32)
```cpp
using Decare = xieite::units::Unit<"area", /* ... */>;
```
#### 33)
```cpp
using Decimilliare = xieite::units::SquareDecimetre;
```
#### 34)
```cpp
using Centiare = xieite::units::SquareMetre;
```
#### 35)
```cpp
using Deciare = xieite::units::Unit<"area", /* ... */>;
```
#### 36)
```cpp
using Are = xieite::units::SquareDecametre;
```
#### 37)
```cpp
using Hectare = xieite::units::SquareHectometre;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto squareMetres = xieite::units::SquareMetre(50);
    auto ares = static_cast<xieite::units::Are>(squareMetres);

    std::println("{} m^2", squareMetres.value);
    std::println("{} a", ares.value);
}
```
Output:
```
50 m^2
0.5 a
```
