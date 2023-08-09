# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:operator/
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::math::BigInteger& comparand) const noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr bool operator==(Integer comparand) const noexcept;
```

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
