# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleFromAll\<\> \{\}
Defined in fragment [xieite:traits.IsNoThrowConvertibleFromAll](../../../src/traits/is_no_throw_convertible_from_all.cpp)

&nbsp;

## [Description](../concepts/no_throw_convertible_from_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename... Sources>
struct IsNoThrowConvertibleFromAll
: std::bool_constant<xieite::concepts::NoThrowConvertibleFromAll<Target, Sources...>> {};
```

&nbsp;

## [Example](../concepts/no_throw_convertible_from_all.md#Example)
