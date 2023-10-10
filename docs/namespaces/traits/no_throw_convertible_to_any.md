# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:NoThrowConvertibleToAny
Defined in header [<xieite/traits/no_throw_convertible_to_any.hpp>](../../../include/xieite/traits/no_throw_convertible_to_any.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct NoThrowConvertibleToAny
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAny<Source, Targets...>> {};
```
