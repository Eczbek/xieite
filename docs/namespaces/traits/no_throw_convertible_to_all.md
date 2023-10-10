# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:NoThrowConvertibleToAll
Defined in header [<xieite/traits/no_throw_convertible_to_all.hpp>](../../../include/xieite/traits/no_throw_convertible_to_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct NoThrowConvertibleToAll
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>> {};
```
