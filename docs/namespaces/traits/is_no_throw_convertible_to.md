# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleTo\<\> \{\}
Defined in fragment [xieite:traits.IsNoThrowConvertibleTo](../../../src/traits/is_no_throw_convertible_to.cpp)

&nbsp;

## [Description](../concepts/no_throw_convertible_to.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
struct IsNoThrowConvertibleTo
: std::bool_constant<xieite::concepts::NoThrowConvertibleTo<Source, Target>> {};
```

&nbsp;

## [Example](../concepts/no_throw_convertible_to.md#Example)
