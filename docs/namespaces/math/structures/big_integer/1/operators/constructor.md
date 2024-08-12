# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Limb_>](../../../big_integer.md)\:\:BigInteger\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Constructs a `xieite::math::BigInteger<Limb_>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
constexpr BigInteger(Integral_ value = 0) noexcept;
```
#### 2)
```cpp
template<typename OtherLimb_>
constexpr BigInteger(const xieite::math::BigInteger<OtherLimb_>& value) noexcept;
```
#### 3)
```cpp
template<std::ranges::Range Range_>
requires(std::same_as<std::ranges::range_value_t<Range_>, Limb_>)
constexpr BigInteger(Range_&& range, bool negative = false) noexcept;
```
#### 4)
```cpp
constexpr BigInteger(std::string_view value, xieite::math::SignedSize radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept;
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
