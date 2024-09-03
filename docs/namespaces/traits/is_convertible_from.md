# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleFrom\<\> \{\}
Defined in fragment [xieite:traits.IsConvertibleFrom](../../../src/traits/is_convertible_from.cpp)

&nbsp;

## [Description](../concepts/convertible_from.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename Source>
struct IsConvertibleFrom
: std::bool_constant<xieite::concepts::ConvertibleFrom<Target, Source>> {};
```

&nbsp;

## [Example](../concepts/convertible_from.md#Example)
