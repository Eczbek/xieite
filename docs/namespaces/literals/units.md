# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:units
Defined in fragment [xieite:literals.units](../../../src/literals/units.cpp)

&nbsp;

## Description
A namespace of literals for constructing various units.

&nbsp;

## Synopsis


&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    using namespace xieite::literals::units;

    std::println("{}", 90_degrees); // converts to radians
}
```
Possible output:
```
1.5707963267948966
```
