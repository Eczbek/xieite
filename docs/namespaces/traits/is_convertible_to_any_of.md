# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConvertibleToAnyOf
Defined in header [<xieite/traits/is_convertible_to_any_of.hpp>](../../../include/xieite/traits/is_convertible_to_any_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToAnyOf
: std::bool_constant<xieite::concepts::ConvertibleToAnyOf<Source, Targets...>> {};
```
