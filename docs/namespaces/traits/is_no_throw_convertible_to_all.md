# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAll
Defined in header [<xieite/traits/is_no_throw_convertible_to_all.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_all.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAll
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>> {};
```
