# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAny\<\> \{\}
Defined in fragment [xieite:traits.IsNoThrowConvertibleToAny](../../../src/traits/is_no_throw_convertible_to_any.cpp)

&nbsp;

## [Description](../concepts/no_throw_convertible_to_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAny
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAny<Source, Targets...>> {};
```

&nbsp;

## [Example](../concepts/no_throw_convertible_to_any.md#Example)
