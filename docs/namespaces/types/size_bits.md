# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:sizeBits
Defined in header [<xieite/types/size_bits.hpp>](../../../include/xieite/types/size_bits.hpp)

&nbsp;

## Description
Defines number of bits in a type

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
inline constexpr std::size_t sizeBits = sizeof(Type) * xieite::system::byteBits;
```
