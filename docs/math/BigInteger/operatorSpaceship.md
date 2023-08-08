# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator/
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& comparand) const noexcept;
```
#### Function parameters
- `comparand` - A `xieite::math::BigInteger` constant reference
#### Return type
- `std::strong_ordering`

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr std::strong_ordering operator<=>(Integer comparand) const noexcept;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `comparand` - - An `Integer`
#### Return type
- `std::strong_ordering`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout
        << std::boolalpha
        << (xieite::math::BigInteger(9) > 3) << '\n';
}
```
Output:
```
true
```
