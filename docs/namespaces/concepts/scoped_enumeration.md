# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ScopedEnumeration\<\>
Defined in fragment [xieite:concepts.ScopedEnumeration](../../../src/concepts/scoped_enumeration.cpp)

&nbsp;

## Description
Specifies that a type is a scoped enumeration.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept ScopedEnumeration = std::is_scoped_enum_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_scoped_enum#Example)
