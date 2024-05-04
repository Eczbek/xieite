# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAny\<\> \{\}
Defined in header [<xieite/traits/is_no_throw_convertible_to_any.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_any.hpp)

&nbsp;

## [Description](../concepts/no_throw_convertible_to_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
struct IsNoThrowConvertibleToAny
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAny<Source_, Targets_...>> {};
```

&nbsp;

## [Example](../concepts/no_throw_convertible_to_any.md#Example)
