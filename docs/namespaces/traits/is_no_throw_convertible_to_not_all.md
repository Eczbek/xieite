# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToNotAll
Defined in header [<xieite/traits/is_no_throw_convertible_to_not_all.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToNotAll
: std::bool_constant<xieite::concepts::NoThrowConvertibleToNotAll<Source, Targets...>> {};
```
