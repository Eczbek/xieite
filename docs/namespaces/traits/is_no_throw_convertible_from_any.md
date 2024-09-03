# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleFromAny\<\> \{\}
Defined in fragment [xieite:traits.IsNoThrowConvertibleFromAny](../../../src/traits/is_no_throw_convertible_from_any.cpp)

&nbsp;

## [Description](../concepts/no_throw_convertible_from_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
struct IsNoThrowConvertibleFromAny
: std::bool_constant<xieite::concepts::NoThrowConvertibleFromAny<Target, Sources...>> {};
```

&nbsp;

## [Example](../concepts/no_throw_convertible_from_any.md#Example)
