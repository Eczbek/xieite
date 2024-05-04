# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAll\<\> \{\}
Defined in header [<xieite/traits/is_no_throw_convertible_to_all.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_all.hpp)

&nbsp;

## [Description](../concepts/no_throw_convertible_to_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
struct IsNoThrowConvertibleToAll
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAll<Source_, Targets_...>> {};
```

&nbsp;

## [Example](../concepts/no_throw_convertible_to_all.md#Example)
