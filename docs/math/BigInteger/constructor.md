# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger](../BigInteger.md)\:\:BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
Constructs a `xieite::math::BigInteger`.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
constexpr BigInteger(Integer value = 0) noexcept;
```
#### 2)
```cpp
constexpr BigInteger(const xieite::math::BigInteger& value) noexcept;
```
#### 3)
```cpp
template<xieite::concepts::RangeOf<bool> BooleanRange>
constexpr BigInteger(const BooleanRange& bits, bool sign = false) noexcept;
```
#### 4)
```cpp
constexpr BigInteger(std::string_view value);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
    std::cout << xieite::math::BigInteger(416).string() << '\n';
}
```
Output:
```
416
```
