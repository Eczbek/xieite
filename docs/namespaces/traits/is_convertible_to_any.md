# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAny
Defined in header [<xieite/traits/is_convertible_to_any.hpp>](../../../include/xieite/traits/is_convertible_to_any.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToAny
: std::bool_constant<xieite::concepts::ConvertibleToAny<Source, Targets...>> {};
```
