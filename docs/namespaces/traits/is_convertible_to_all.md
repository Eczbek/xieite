# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAll\<\> \{\}
Defined in fragment [xieite:traits.IsConvertibleToAll](../../../src/traits/is_convertible_to_all.cpp)

&nbsp;

## [Description](../concepts/convertible_to_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToAll
: std::bool_constant<xieite::concepts::ConvertibleToAll<Source, Targets...>> {};
```

&nbsp;

## [Example](../concepts/convertible_to_all.md#Example)
