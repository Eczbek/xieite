# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:byteBits
Defined in header [<xieite/system/byte_bits.hpp>](../../../include/xieite/system/byte_bits.hpp)

&nbsp;

## Description
Defines the amount of bits per byte on this system.

&nbsp;

## Synopsis
#### 1)
```cpp
inline constexpr std::size_t byteBits = std::numeric_limits<unsigned char>::digits;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/system/byte_bits.hpp"

int main() {
    std::println("{}", xieite::system::byteBits);
}
```
Possible output:
```
8
```
