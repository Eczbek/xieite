# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAll\<\> \{\}
Defined in header [<xieite/traits/is_convertible_to_all.hpp>](../../../include/xieite/traits/is_convertible_to_all.hpp)

&nbsp;

## [Description](../concepts/convertible_to_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
struct IsConvertibleToAll
: std::bool_constant<xieite::concepts::ConvertibleToAll<Source_, Targets_...>> {};
```

&nbsp;

## [Example](../concepts/convertible_to_all.md#Example)
