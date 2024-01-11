# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:ShorterInteger
Defined in header [<xieite/types/shorter_integer.hpp>](../../../include/xieite/types/shorter_integer.hpp)

&nbsp;

## Description
Gets the next larger unsigned integer type.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Type>
template<std::integral Type>
using ShorterInteger = std::conditional_t<std::same_as<Type, std::uint64_t>, std::uint32_t, std::conditional_t<std::same_as<Type, std::int64_t>, std::int32_t, std::conditional_t<std::same_as<Type, std::uint32_t>, std::uint16_t, std::conditional_t<std::same_as<Type, std::int32_t>, std::int16_t, std::conditional_t<std::same_as<Type, std::uint16_t>, std::uint8_t, std::conditional_t<std::same_as<Type, std::int16_t>, std::int8_t, bool>>>>>>;
```
