# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSpecializationOfAll\<\> \{\}
Defined in header [<xieite/traits/is_specialization_of_all.hpp>](../../../include/xieite/traits/is_specialization_of_all.hpp)

&nbsp;

## [Description](../concepts/specialization_of_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename...> typename... Templates_>
struct IsSpecializationOfAll
: std::bool_constant<xieite::concepts::SpecializationOfAll<Type_, Templates_...>> {};
```

&nbsp;

## [Example](../concepts/specialization_of_all.md#Example)
