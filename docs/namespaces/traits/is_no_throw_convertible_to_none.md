# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToNone
Defined in header [<xieite/traits/is_no_throw_convertible_to_none.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToNone
: std::bool_constant<xieite::concepts::NoThrowConvertibleToNone<Source, Targets...>> {};
```
