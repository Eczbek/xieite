# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\: \(area\)
Defined in fragment [xieite:units.area](../../../src/units/area.cpp)

&nbsp;

## Description
A collection of type aliases for area units.

&nbsp;

## Synopsis
#### 1)
```cpp
using SquareQuectometer = xieite::units::Unit<"area", /* ... */>;
```
#### 2)
```cpp
using SquareRontometer = xieite::units::Unit<"area", /* ... */>;
```
#### 3)
```cpp
using SquareYoctometer = xieite::units::Unit<"area", /* ... */>;
```
#### 4)
```cpp
using SquareZeptometer = xieite::units::Unit<"area", /* ... */>;
```
#### 5)
```cpp
using SquareAttometer = xieite::units::Unit<"area", /* ... */>;
```
#### 6)
```cpp
using SquareFemtometer = xieite::units::Unit<"area", /* ... */>;
```
#### 7)
```cpp
using SquarePicometer = xieite::units::Unit<"area", /* ... */>;
```
#### 8)
```cpp
using SquareNanometer = xieite::units::Unit<"area", /* ... */>;
```
#### 9)
```cpp
using SquareMicrometer = xieite::units::Unit<"area", /* ... */>;
```
#### 10)
```cpp
using SquareMillimeter = xieite::units::Unit<"area", /* ... */>;
```
#### 11)
```cpp
using SquareCentimeter = xieite::units::Unit<"area", /* ... */>;
```
#### 12)
```cpp
using SquareDecimeter = xieite::units::Unit<"area", /* ... */>;
```
#### 13)
```cpp
using SquareMeter = xieite::units::Unit<"area", /* ... */>;
```
#### 14)
```cpp
using SquareDecameter = xieite::units::Unit<"area", /* ... */>;
```
#### 15)
```cpp
using SquareHectometer = xieite::units::Unit<"area", /* ... */>;
```
#### 16)
```cpp
using SquareKilometer = xieite::units::Unit<"area", /* ... */>;
```
#### 17)
```cpp
using SquareMegameter = xieite::units::Unit<"area", /* ... */>;
```
#### 18)
```cpp
using SquareGigameter = xieite::units::Unit<"area", /* ... */>;
```
#### 19)
```cpp
using SquareTerameter = xieite::units::Unit<"area", /* ... */>;
```
#### 20)
```cpp
using SquarePetameter = xieite::units::Unit<"area", /* ... */>;
```
#### 21)
```cpp
using SquareExameter = xieite::units::Unit<"area", /* ... */>;
```
#### 22)
```cpp
using SquareZettameter = xieite::units::Unit<"area", /* ... */>;
```
#### 23)
```cpp
using SquareYottameter = xieite::units::Unit<"area", /* ... */>;
```
#### 24)
```cpp
using SquareRonnameter = xieite::units::Unit<"area", /* ... */>;
```
#### 25)
```cpp
using SquareQuettameter = xieite::units::Unit<"area", /* ... */>;
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
using Decimilliare = xieite::units::SquareDecimeter;
```
#### 34)
```cpp
using Centiare = xieite::units::SquareMeter;
```
#### 35)
```cpp
using Deciare = xieite::units::Unit<"area", /* ... */>;
```
#### 36)
```cpp
using Are = xieite::units::SquareDecameter;
```
#### 37)
```cpp
using Hectare = xieite::units::SquareHectometer;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto squareMeters = xieite::units::SquareMeter(50);
    auto ares = static_cast<xieite::units::Are>(squareMeters);

    std::println("{} m^2", squareMeters.value);
    std::println("{} a", ares.value);
}
```
Output:
```
50 m^2
0.5 a
```
