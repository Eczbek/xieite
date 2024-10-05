# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\: \(length\)
Defined in fragment [xieite:units.length](../../../src/units/length.cpp)

&nbsp;

## Description
A collection of type aliases for length units.

&nbsp;

## Synopsis
#### 1)
```cpp
using Quectometer = xieite::units::Unit<"length", /* ... */>;
```
#### 2)
```cpp
using Rontometer = xieite::units::Unit<"length", /* ... */>;
```
#### 3)
```cpp
using Yoctometer = xieite::units::Unit<"length", /* ... */>;
```
#### 4)
```cpp
using Zeptometer = xieite::units::Unit<"length", /* ... */>;
```
#### 5)
```cpp
using Attometer = xieite::units::Unit<"length", /* ... */>;
```
#### 6)
```cpp
using Femtometer = xieite::units::Unit<"length", /* ... */>;
```
#### 7)
```cpp
using Picometer = xieite::units::Unit<"length", /* ... */>;
```
#### 8)
```cpp
using Nanometer = xieite::units::Unit<"length", /* ... */>;
```
#### 9)
```cpp
using Micrometer = xieite::units::Unit<"length", /* ... */>;
```
#### 10)
```cpp
using Millimeter = xieite::units::Unit<"length", /* ... */>;
```
#### 11)
```cpp
using Centimeter = xieite::units::Unit<"length", /* ... */>;
```
#### 12)
```cpp
using Decimeter = xieite::units::Unit<"length", /* ... */>;
```
#### 13)
```cpp
using Meter = xieite::units::Unit<"length", /* ... */>;
```
#### 14)
```cpp
using Decameter = xieite::units::Unit<"length", /* ... */>;
```
#### 15)
```cpp
using Hectometer = xieite::units::Unit<"length", /* ... */>;
```
#### 16)
```cpp
using Kilometer = xieite::units::Unit<"length", /* ... */>;
```
#### 17)
```cpp
using Megameter = xieite::units::Unit<"length", /* ... */>;
```
#### 18)
```cpp
using Gigameter = xieite::units::Unit<"length", /* ... */>;
```
#### 19)
```cpp
using Terameter = xieite::units::Unit<"length", /* ... */>;
```
#### 20)
```cpp
using Petameter = xieite::units::Unit<"length", /* ... */>;
```
#### 21)
```cpp
using Exameter = xieite::units::Unit<"length", /* ... */>;
```
#### 22)
```cpp
using Zettameter = xieite::units::Unit<"length", /* ... */>;
```
#### 23)
```cpp
using Yottameter = xieite::units::Unit<"length", /* ... */>;
```
#### 24)
```cpp
using Ronnameter = xieite::units::Unit<"length", /* ... */>;
```
#### 25)
```cpp
using Quettameter = xieite::units::Unit<"length", /* ... */>;
```
#### 26)
```cpp
using Twip = xieite::units::Unit<"length", /* ... */>;
```
#### 27)
```cpp
using Thou = xieite::units::Unit<"length", /* ... */>;
```
#### 28)
```cpp
using Barleycorn = xieite::units::Unit<"length", /* ... */>;
```
#### 29)
```cpp
using Inch = xieite::units::Unit<"length", /* ... */>;
```
#### 30)
```cpp
using Foot = xieite::units::Unit<"length", /* ... */>;
```
#### 31)
```cpp
using Yard = xieite::units::Unit<"length", /* ... */>;
```
#### 32)
```cpp
using Chain = xieite::units::Unit<"length", /* ... */>;
```
#### 33)
```cpp
using Furlong = xieite::units::Unit<"length", /* ... */>;
```
#### 34)
```cpp
using Mile = xieite::units::Unit<"length", /* ... */>;
```
#### 35)
```cpp
using League = xieite::units::Unit<"length", /* ... */>;
```
#### 36)
```cpp
using Fathom = xieite::units::Unit<"length", /* ... */>;
```
#### 37)
```cpp
using Cable = xieite::units::Unit<"length", /* ... */>;
```
#### 38)
```cpp
using NauticalMile = xieite::units::Unit<"length", /* ... */>;
```
#### 39)
```cpp
using NauticalLeague = xieite::units::Unit<"length", /* ... */>;
```
#### 40)
```cpp
using Link = xieite::units::Unit<"length", /* ... */>;
```
#### 41)
```cpp
using Rod = xieite::units::Unit<"length", /* ... */>;
```
#### 42)
```cpp
using Perch = xieite::units::Rod;
```
#### 43)
```cpp
using Pole = xieite::units::Rod;
```
#### 44)
```cpp
using Lug = xieite::units::Rod;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto millimeters = xieite::units::Millimeter(999);
    auto meters = static_cast<xieite::units::Meter>(millimeters);

    std::println("{} mm", millimeters.value);
    std::println("{} m", meters.value);
}
```
Possible output:
```
999 mm
0.999 m
```
