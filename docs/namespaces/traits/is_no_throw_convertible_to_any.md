# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAny
Defined in header [<xieite/traits/is_no_throw_convertible_to_any.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_any.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAny
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAny<Source, Targets...>> {};
```
