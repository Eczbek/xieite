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
constexpr std::string toBase(const xieite::math::Base& base, Integer value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/binary.hpp>
#include <xieite/math/toBase.hpp>

int main() {
    std::cout << xieite::math::toBase(xieite::math::binary, 13) << '\n';
}
```
Output:
```
1101
```
