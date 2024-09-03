# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleFrom\<\> \{\}
Defined in fragment [xieite:traits.IsNoThrowConvertibleFrom](../../../src/traits/is_convertible_from.cpp)

&nbsp;

## [Description](../concepts/convertible_from.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename Source>
struct IsNoThrowConvertibleFrom
: std::bool_constant<xieite::concepts::NoThrowConvertibleFrom<Target, Source>> {};
```

&nbsp;

## [Example](../concepts/convertible_from.md#Example)
