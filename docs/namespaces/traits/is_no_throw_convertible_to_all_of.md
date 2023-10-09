# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAllOf
Defined in header [<xieite/traits/is_no_throw_convertible_to_all_of.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_all_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAllOf
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAllOf<Source, Targets...>> {};
```
