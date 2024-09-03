# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleFromAll\<\> \{\}
Defined in fragment [xieite:traits.IsConvertibleFromAll](../../../src/traits/is_convertible_from_all.cpp)

&nbsp;

## [Description](../concepts/convertible_from_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
struct IsConvertibleFromAll
: std::bool_constant<xieite::concepts::ConvertibleFromAll<Target, Sources...>> {};
```

&nbsp;

## [Example](../concepts/convertible_from_all.md#Example)
