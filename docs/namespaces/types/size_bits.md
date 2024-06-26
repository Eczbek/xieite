# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:sizeBits\<\>
Defined in header [<xieite/types/size_bits.hpp>](../../../include/xieite/types/size_bits.hpp)

&nbsp;

## Description
Defines number of bits in a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
inline constexpr std::size_t sizeBits = sizeof(Type_) * xieite::system::byteBits;
```
#### 2)
```cpp
template<std::integral Integral_>
inline constexpr std::size_t sizeBits<Integral_> = std::numeric_limits<Integral_>::digits + std::numeric_limits<Integral_>::is_signed;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/types/size_bits.hpp"

int main() {
    std::println("{}", xieite::types::sizeBits<std::uint16_t>);
}
```
Output:
```
16
```
