# [xieite](../xieite.md)\:\:[math](../math.md)\:\:toBase
Defined in header [<xieite/math/toBase.hpp>](../../include/xieite/math/toBase.hpp)

&nbsp;

## Description
Converts an integer to a string in any base. Allows negative bases. Can be used as a compile-time method of stringifying integers.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr std::string toBase(Integer value, int radix, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", char negativeSign = '-', bool caseSensitive = false) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/binary.hpp>
#include <xieite/math/toBase.hpp>

int main() {
    std::cout << xieite::math::toBase(13, 2) << '\n';
}
```
Output:
```
1101
```
