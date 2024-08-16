# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsTemplateOfAny\<\> \{\}
Defined in header [<xieite/traits/is_template_of_any.hpp>](../../../include/xieite/traits/is_template_of_any.hpp)

&nbsp;

## [Description](../concepts/template_of_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename...> typename... Templates>
struct IsTemplateOfAny
: std::bool_constant<xieite::concepts::TemplateOfAny<Type, Templates...>> {};
```

&nbsp;

## [Example](../concepts/template_of_any.md#Example)
