# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Datum>](../../../../big_integer.md)\:\:operator typename
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Casts a `xieite::math::BigInteger` to any other arithmetic type.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr operator Integer() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr operator bool() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/big_integer.hpp>

int main() {
    std::cout
        << std::boolalpha
        << static_cast<bool>(xieite::math::BigInteger(4))
        << '\n';
}
```
Output:
```
true
```