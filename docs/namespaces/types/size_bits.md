# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:sizeBits
Defined in header [<xieite/types/size_bits.hpp>](../../../include/xieite/types/size_bits.hpp)

&nbsp;

## Description
Defines number of bits in a type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
inline constexpr std::size_t sizeBits = sizeof(Type) * xieite::system::byteBits;
```
#### 2)
```cpp
template<std::integral Integral>
inline constexpr std::size_t sizeBits<Integral> = std::numeric_limits<Integral>::digits + std::numeric_limits<Integral>::is_signed;
```
