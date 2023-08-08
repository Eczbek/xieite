# [xieite](../xieite.md)\:\:[types](../types.md)\:\:sizeBits
Defined in header [<xieite/types/sizeBits.hpp>](../../include/xieite/types/sizeBits.hpp)

&nbsp;

## Description
Defines number of bits in a type

&nbsp;

## Synopsis
```cpp
template<typename Any>
inline constexpr std::size_t sizeBits = sizeof(Any) * xieite::system::bitsPerByte;
```
#### Template parameters
- `Any` - Any type
