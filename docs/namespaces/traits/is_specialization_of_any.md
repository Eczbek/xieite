# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSpecializationOfAny\<\> \{\}
Defined in header [<xieite/traits/is_specialization_of_any.hpp>](../../../include/xieite/traits/is_specialization_of_any.hpp)

&nbsp;

## [Description](../concepts/specialization_of_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename...> typename... Templates_>
struct IsSpecializationOfAny
: std::bool_constant<xieite::concepts::SpecializationOfAny<Type_, Templates_...>> {};
```

&nbsp;

## [Example](../concepts/specialization_of_any.md#Example)
