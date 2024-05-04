# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAny\<\> \{\}
Defined in header [<xieite/traits/is_convertible_to_any.hpp>](../../../include/xieite/traits/is_convertible_to_any.hpp)

&nbsp;

## [Description](../concepts/convertible_to_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source_, typename... Targets_>
struct IsConvertibleToAny
: std::bool_constant<xieite::concepts::ConvertibleToAny<Source_, Targets_...>> {};
```

&nbsp;

## [Example](../concepts/convertible_to_any.md#Example)
