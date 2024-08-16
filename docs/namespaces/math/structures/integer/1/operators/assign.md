# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator=\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Assigns this integer to another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator=(xieite::math::Integer<bits, sign> value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<5, false> integer = 17;

    integer = 41;

    std::println("{}", integer.data());
}
```
Output:
```
9
```
