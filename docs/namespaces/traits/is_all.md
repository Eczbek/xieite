# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAll\<\> \{\}
Defined in header [<xieite/traits/is_all.hpp>](../../../include/xieite/traits/is_all.hpp)

&nbsp;

## [Description](../concepts/all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename> typename... Traits_>
struct IsAll
: std::bool_constant<xieite::concepts::All<Type_, Traits_...>> {};
```

&nbsp;

## [Example](../concepts/all.md#Example)
