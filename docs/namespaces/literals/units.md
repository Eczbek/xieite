# [xieite](../../xieite.md)\:\:[literals](../../literals.md)\:\:units
Defined in header [<xieite/literals/units.hpp>](../../../include/xieite/literals/units.hpp)

&nbsp;

## Description
A namespace of literals for constructing various units.

&nbsp;

## Synopsis


&nbsp;

## Example
```cpp
#include <print>
#include "xieite/literals/units.hpp"

int main() {
    using namespace xieite::literals::units;

    std::println("{}", 90_degrees); // converts to radians
}
```
Possible output:
```
1.5707963267948966
```
