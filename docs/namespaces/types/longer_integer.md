# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:LongerInteger
Defined in header [<xieite/types/longer_integer.hpp>](../../../include/xieite/types/longer_integer.hpp)

&nbsp;

## Description
Gets the next larger unsigned integer type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Type>
using LongerInteger = std::conditional_t<std::same_as<Type, bool>, std::uint8_t, std::conditional_t<std::same_as<Type, std::uint8_t>, std::uint16_t, std::conditional_t<std::same_as<Type, std::int8_t>, std::int16_t, std::conditional_t<std::same_as<Type, std::uint16_t>, std::uint32_t, std::conditional_t<std::same_as<Type, std::int16_t>, std::int32_t, std::conditional_t<std::unsigned_integral<Type>, std::uint64_t, std::int64_t>>>>>>;
```
