# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb>](../../../big_integer.md)\:\:BigInteger\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Constructs a `xieite::math::BigInteger<Limb>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
explicit(false) constexpr BigInteger(Integral value = 0) noexcept;
```
#### 2)
```cpp
template<typename OtherLimb>
explicit constexpr BigInteger(const xieite::math::BigInteger<OtherLimb>& value) noexcept;
```
#### 3)
```cpp
template<std::ranges::input_range Range>
requires(std::same_as<std::ranges::range_value_t<Range>, Limb>)
explicit constexpr BigInteger(Range&& range, bool negative = false) noexcept;
```
#### 4)
```cpp
explicit(false) constexpr BigInteger(std::string_view value, xieite::math::SignedSize radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", xieite::math::BigInteger(418).string());
}
```
Output:
```
418
```
