# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToNotAll
Defined in header [<xieite/traits/is_convertible_to_not_all.hpp>](../../../include/xieite/traits/is_convertible_to_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToNotAll
: std::bool_constant<xieite::concepts::ConvertibleToNotAll<Source, Targets...>> {};
```
