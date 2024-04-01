# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsTemplateOf \{\}
Defined in header [<xieite/traits/is_template_of.hpp>](../../../include/xieite/traits/is_template_of.hpp)

&nbsp;

## [Description](../concepts/template_of.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<template<typename...> typename Template, typename Type>
struct IsTemplateOf
: std::bool_constant<xieite::concepts::TemplateOf<Template, Type>> {};
```

&nbsp;

## [Example](../concepts/template_of.md#Example)
