# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToNone
Defined in header [<xieite/traits/is_convertible_to_none.hpp>](../../../include/xieite/traits/is_convertible_to_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToNone
: std::bool_constant<xieite::concepts::ConvertibleToNone<Source, Targets...>> {};
```
