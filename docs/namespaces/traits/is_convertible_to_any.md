# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAny\<\> \{\}
Defined in fragment [xieite:traits.IsConvertibleToAny](../../../src/traits/is_convertible_to_any.cpp)

&nbsp;

## [Description](../concepts/convertible_to_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToAny
: std::bool_constant<xieite::concepts::ConvertibleToAny<Source, Targets...>> {};
```

&nbsp;

## [Example](../concepts/convertible_to_any.md#Example)
