# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:size\<\>
Defined in header [<xieite/bits/size.hpp>](../../../include/xieite/bits/size.hpp)

&nbsp;

## Description
Defines the number of bits in a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
inline constexpr std::size_t size = sizeof(Type_) * CHAR_BIT;
```
#### 2)
```cpp
template<std::integral Integral_>
inline constexpr std::size_t size<Integral_> = std::numeric_limits<Integral_>::digits + std::numeric_limits<Integral_>::is_signed;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/bits/size.hpp"

int main() {
    std::println("{}", xieite::bits::size<std::uint16_t>);
}
```
Possible output:
```
16
```
