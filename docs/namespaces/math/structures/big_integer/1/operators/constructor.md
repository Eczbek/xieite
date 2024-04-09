# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:BigInteger\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Constructs a `xieite::math::BigInteger<Word>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
constexpr BigInteger(Integral value = 0) noexcept;
```
#### 2)
```cpp
template<typename OtherWord>
constexpr BigInteger(const xieite::math::BigInteger<OtherWord>& value) noexcept;
```
#### 3)
```cpp
template<std::ranges::Range Range>
requires(std::same_as<std::ranges::range_value_t<Range>, Word>)
constexpr BigInteger(Range&& range, bool negative = false) noexcept;
```
#### 4)
```cpp
constexpr BigInteger(std::string_view value, xieite::math::SignedSize radix = 10, xieite::strings::IntegerComponents components = xieite::strings::IntegerComponents()) noexcept;
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
