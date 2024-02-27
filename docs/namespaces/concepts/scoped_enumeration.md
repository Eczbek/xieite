# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ScopedEnumeration
Defined in header [<xieite/concepts/scoped_enumeration.hpp>](../../../include/xieite/concepts/scoped_enumeration.hpp)

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
