# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSpecializationOf\<\> \{\}
Defined in header [<xieite/traits/is_specialization_of.hpp>](../../../include/xieite/traits/is_specialization_of.hpp)

&nbsp;

## [Description](../concepts/specialization_of.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename, template<typename...> typename>
struct IsSpecializationOf
: std::false_type {};
```
#### 2)
```cpp
template<template<typename...> typename Template_, typename... Arguments_>
struct IsSpecializationOf<Template_<Arguments...>, Template_>
: std::true_type {};
```

&nbsp;

## [Example](../concepts/specialization_of.md#Example)
