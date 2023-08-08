# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator typename
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Casts a `xieite::math::BigInteger` to any other arithmetic type

&nbsp;

## Synopses

&nbsp;

```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr operator Arithmetic() const noexcept;
```
#### Template parameters
- `Arithmetic` - Any arithmetic type satisfying `xieite::concepts::Arithmetic`

&nbsp;

```cpp
[[nodiscard]]
constexpr operator bool() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout
        << std::boolalpha
        << static_cast<bool>(xieite::math::BigInteger(4)) << '\n';
}
```
Output:
```
true
```
