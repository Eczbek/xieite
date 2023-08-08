# [xieite](../xieite.md)\:\:[system](../system.md)\:\:bitsPerByte
Defined in header [<xieite/system/bitsPerByte.hpp>](../../include/xieite/system/bitsPerByte.hpp)

&nbsp;

## Description
Defines the amount of bits per byte on this system

&nbsp;

## Synopsis
```cpp
inline constexpr std::size_t bitsPerByte = std::numeric_limits<unsigned char>::digits;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/bitsPerByte.hpp>

int main() {
    std::cout << xieite::system::bitsPerByte << '\n';
}
```
Possible output:
```
8
```
