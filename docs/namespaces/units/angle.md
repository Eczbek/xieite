# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\: \(angle\)
Defined in fragment [xieite:units.angle](../../../src/units/angle.cpp)

&nbsp;

## Description
A collection of type aliases for angle units.

&nbsp;

## Synopsis
#### 1)
```cpp
using Radian = xieite::units::Unit<"angle", /* ... */>;
```
#### 2)
```cpp
using Degree = xieite::units::Unit<"angle", /* ... */>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto degrees = xieite::units::Degree(45);
    auto radians = static_cast<xieite::units::Radian>(degrees);

    std::println("{} deg", degrees.value);
    std::println("{} rad", radians.value);
}
```
Output:
```
45 deg
0.7853981633974483 rad
```
