# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsTemplateOfAll\<\> \{\}
Defined in fragment [xieite:traits.IsTemplateOfAll](../../../src/traits/is_template_of_all.cpp)

&nbsp;

## [Description](../concepts/template_of_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename...> typename... Templates>
struct IsTemplateOfAll
: std::bool_constant<xieite::concepts::TemplateOfAll<Type, Templates...>> {};
```

&nbsp;

## [Example](../concepts/template_of_all.md#Example)
