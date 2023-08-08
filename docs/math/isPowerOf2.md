# [xieite](../xieite.md)\:\:[math](../math.md)\:\:isPowerOf2
Defined in header [<xieite/math/isPowerOf2.hpp>](../../include/xieite/math/isPowerOf2.hpp)

&nbsp;

## Description
Checks that a value is a power of 2

&nbsp;

## Synopsis
```cpp
template<std::unsigned_integral UnsignedInteger>
[[nodiscard]]
constexpr bool isPowerOf2(const UnsignedInteger value) noexcept;
```
#### Template parameters
- `UnsignedInteger` - An unsigned integral type satisfying `std::unsigned_integral`
#### Function parameters
- `value` - An `UnsignedInteger`
#### Return type
- `bool`, whether or not value is a power of 2

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/isPowerOf2.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::math::isPowerOf2(4) << '\n'
        << xieite::math::isPowerOf2(0) << '\n';
}
```
Output:
```
true
false
```
