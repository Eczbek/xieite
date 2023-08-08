# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator/
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::math::BigInteger& comparand) const noexcept;
```
#### Function parameters
- `comparand` - A `xieite::math::BigInteger` constant reference
#### Return type
- `bool`, whether or not the two values are equal

&nbsp;

```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr bool operator==(const Integer comparand) const noexcept;
```
#### Template parameters
- `Integer` - A type satisfying `std::integral`
#### Function parameters
- `comparand` - - An `Integer`
#### Return type
- `bool`, whether or not the two values are equal

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout
        << std::boolalpha
        << (xieite::math::BigInteger(2) == 2) << '\n';
}
```
Output:
```
true
```
