# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[BigInteger<Word>](../../../../big_integer.md)\:\:operator typename\(\)
Defined in header [<xieite/math/big_integer.hpp>](../../../../../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
Casts a `xieite::math::BigInteger<Word>` to any other arithmetic type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr operator Integer() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] constexpr operator bool() const noexcept;
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
