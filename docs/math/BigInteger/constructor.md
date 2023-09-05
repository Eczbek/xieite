# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:[BigInteger<Datum>](../BigInteger.md)\:\:BigInteger
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
constexpr BigInteger(const xieite::math::BigInteger<Datum>& value) noexcept;
```
#### 3)
```cpp
template<std::ranges::Range Range>
requires(std::same_as<Datum, std::ranges::range_value_t<Range>>)
constexpr BigInteger(const Range& range, bool negative = false) noexcept;
```
#### 4)
```cpp
constexpr BigInteger(std::string_view value, int base = 10, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", char sign = '-') noexcept;
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
