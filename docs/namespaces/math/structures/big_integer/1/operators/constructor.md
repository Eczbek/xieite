# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../big_integer.md)\:\:BigInteger
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Constructs a `xieite::math::BigInteger`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
constexpr BigInteger(Integer value = 0) noexcept;
```
#### 2)
```cpp
constexpr BigInteger(const xieite::math::BigInteger<Word>& value) noexcept;
```
#### 3)
```cpp
template<std::ranges::Range Range>
requires(std::same_as<std::ranges::range_value_t<Range>, Word>)
constexpr BigInteger(const Range& range, bool negative = false) noexcept;
```
#### 4)
```cpp
constexpr BigInteger(std::string_view value, xieite::math::SignedSize radix = 10, const xieite::math::IntegerStringComponents& components = xieite::math::IntegerStringComponents()) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/big_integer.hpp"

int main() {
    std::cout << xieite::math::BigInteger(418).string() << '\n';
}
```
Output:
```
416
```
