# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsTemplateOfAny\<\> \{\}
Defined in header [<xieite/traits/is_template_of_any.hpp>](../../../include/xieite/traits/is_template_of_any.hpp)

&nbsp;

## [Description](../concepts/template_of_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename...> typename... Templates_>
struct IsTemplateOfAny
: std::bool_constant<xieite::concepts::TemplateOfAny<Type_, Templates_...>> {};
```

&nbsp;

## [Example](../concepts/template_of_any.md#Example)
