# [xieite](../xieite.md)\:\:[math](../math.md)\:\:almostEqual
Defined in header [<xieite/math/almostEqual.hpp>](../../include/xieite/math/almostEqual.hpp)

&nbsp;

## Description
Checks if two values are almost equal

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
[[nodiscard]]
constexpr bool almostEqual(const Arithmetic1 value1, const Arithmetic2 value2) noexcept;
```
#### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `value1` - An `Arithmetic1`
- `value2` - An `Arithmetic2`
#### Return type
- `bool`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/almostEqual.hpp>

int main() {
    const double a = 0.3;
    const double b = 0.1 + 0.2;
    
    std::cout
        << std::boolalpha
        << (a == b) << '\n'
        << xieite::math::almostEqual(a, b) << '\n';
}
```
Output:
```
false
true
```
