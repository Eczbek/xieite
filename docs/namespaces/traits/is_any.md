# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAny \{\}
Defined in header [<xieite/traits/is_any.hpp>](../../../include/xieite/traits/is_any.hpp)

&nbsp;

## [Description](../concepts/any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsAny
: std::bool_constant<xieite::concepts::Any<Type, Traits...>> {};
```

&nbsp;

## [Example](../concepts/any.md#Example)
