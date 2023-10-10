# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:ConvertibleToNone
Defined in header [<xieite/traits/convertible_to_none.hpp>](../../../include/xieite/traits/convertible_to_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct ConvertibleToNone
: std::bool_constant<xieite::concepts::ConvertibleToNone<Source, Targets...>> {};
```
