# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word_>](../../../../big_integer.md)\:\:operator typename\<\>\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Casts a `xieite::math::BigInteger<Word_>` to any other arithmetic type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
[[nodiscard]] explicit constexpr operator Integral() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] explicit constexpr operator bool() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", static_cast<bool>(xieite::math::BigInteger(4)));
}
```
Output:
```
true
```
