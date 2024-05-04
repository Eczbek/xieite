# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAny\<\> \{\}
Defined in header [<xieite/traits/is_any.hpp>](../../../include/xieite/traits/is_any.hpp)

&nbsp;

## [Description](../concepts/any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename> typename... Traits_>
struct IsAny
: std::bool_constant<xieite::concepts::Any<Type_, Traits_...>> {};
```

&nbsp;

## [Example](../concepts/any.md#Example)
