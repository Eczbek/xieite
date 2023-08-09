# [xieite](../xieite.md)\:\:[math](../math.md)\:\:toBase
Defined in header [<xieite/math/toBase.hpp>](../../include/xieite/math/toBase.hpp)

&nbsp;

## Description
Converts an integer to a string in any base. Allows negative bases. Doubles as a compile-time method of stringifying integers.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer = int>
[[nodiscard]]
constexpr std::string toBase(int base, Integer value, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz");
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/toBase.hpp>

int main() {
    std::cout << xieite::math::toBase(2, 13) << '\n';
}
```
Output:
```
1101
```
