# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsTemplateOfAny\<\> \{\}
Defined in fragment [xieite:traits.IsTemplateOfAny](../../../src/traits/is_template_of_any.cpp)

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
