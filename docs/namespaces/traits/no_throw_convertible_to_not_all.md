# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:NoThrowConvertibleToNotAll
Defined in header [<xieite/traits/no_throw_convertible_to_not_all.hpp>](../../../include/xieite/traits/no_throw_convertible_to_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct NoThrowConvertibleToNotAll
: std::bool_constant<xieite::concepts::NoThrowConvertibleToNotAll<Source, Targets...>> {};
```
