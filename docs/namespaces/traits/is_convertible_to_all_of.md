# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAllOf
Defined in header [<xieite/traits/is_convertible_to_all_of.hpp>](../../../include/xieite/traits/is_convertible_to_all_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToAllOf
: std::bool_constant<xieite::concepts::ConvertibleToAllOf<Source, Targets...>> {};
```
