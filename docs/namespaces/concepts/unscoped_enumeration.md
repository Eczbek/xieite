# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:UnscopedEnumeration
Defined in header [<xieite/concepts/unscoped_enumeration.hpp>](../../../include/xieite/concepts/unscoped_enumeration.hpp)

&nbsp;

## Description
Specifies that a type is an unscoped enumeration.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept UnscopedEnumeration = std::is_enum_v<Type> && std::convertible_to<Type, std::underlying_type_t<Type>>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_scoped_enum#Example)
