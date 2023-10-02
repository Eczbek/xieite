# [xieite](../xieite.md)\:\:[system](../system.md)\:\:byteBits
Defined in header [<xieite/system/byteBits.hpp>](../../include/xieite/system/byteBits.hpp)

&nbsp;

## Description
Defines the amount of bits per byte on this system.

&nbsp;

## Synopses
#### 1)
```cpp
inline constexpr std::size_t byteBits = std::numeric_limits<unsigned char>::digits;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/byteBits.hpp>

int main() {
    std::cout << xieite::system::byteBits << '\n';
}
```
Possible output:
```
8
```
