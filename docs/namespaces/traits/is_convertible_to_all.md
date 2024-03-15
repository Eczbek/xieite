# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAll
Defined in header [<xieite/traits/is_convertible_to_all.hpp>](../../../include/xieite/traits/is_convertible_to_all.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToAll
: std::bool_constant<xieite::concepts::ConvertibleToAll<Source, Targets...>> {};
```
