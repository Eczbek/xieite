# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleFromAny\<\> \{\}
Defined in fragment [xieite:traits.IsConvertibleFromAny](../../../src/traits/is_convertible_from_any.cpp)

&nbsp;

## [Description](../concepts/convertible_from_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
struct IsConvertibleFromAny
: std::bool_constant<xieite::concepts::ConvertibleFromAny<Target, Sources...>> {};
```

&nbsp;

## [Example](../concepts/convertible_from_any.md#Example)
