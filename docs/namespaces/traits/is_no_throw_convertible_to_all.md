# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAll\<\> \{\}
Defined in fragment [xieite:traits.IsNoThrowConvertibleToAll](../../../src/traits/is_no_throw_convertible_to_all.cpp)

&nbsp;

## [Description](../concepts/no_throw_convertible_to_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAll
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>> {};
```

&nbsp;

## [Example](../concepts/no_throw_convertible_to_all.md#Example)
