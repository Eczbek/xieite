# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:UnscopedEnumeration\<\>
Defined in fragment [xieite:concepts.UnscopedEnumeration](../../../src/concepts/unscoped_enumeration.cpp)

&nbsp;

## Description
Specifies that a type is an unscoped enumeration.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept UnscopedEnumeration = std::is_enum_v<Type> && !std::is_scoped_enum_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_scoped_enum#Example)
