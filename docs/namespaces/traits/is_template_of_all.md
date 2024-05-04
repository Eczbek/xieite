# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsTemplateOfAll\<\> \{\}
Defined in header [<xieite/traits/is_template_of_all.hpp>](../../../include/xieite/traits/is_template_of_all.hpp)

&nbsp;

## [Description](../concepts/template_of_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename...> typename... Templates_>
struct IsTemplateOfAll
: std::bool_constant<xieite::concepts::TemplateOfAll<Type_, Templates_...>> {};
```

&nbsp;

## [Example](../concepts/template_of_all.md#Example)
