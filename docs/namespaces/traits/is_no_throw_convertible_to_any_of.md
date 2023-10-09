# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAnyOf
Defined in header [<xieite/traits/is_no_throw_convertible_to_any_of.hpp>](../../../include/xieite/traits/is_no_throw_convertible_to_any_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAnyOf
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAnyOf<Source, Targets...>> {};
```
