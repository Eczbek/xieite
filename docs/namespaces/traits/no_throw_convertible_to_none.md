# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:NoThrowConvertibleToNone
Defined in header [<xieite/traits/no_throw_convertible_to_none.hpp>](../../../include/xieite/traits/no_throw_convertible_to_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct NoThrowConvertibleToNone
: std::bool_constant<xieite::concepts::NoThrowConvertibleToNone<Source, Targets...>> {};
```
