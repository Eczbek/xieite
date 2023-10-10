# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:ConvertibleToAny
Defined in header [<xieite/traits/convertible_to_any.hpp>](../../../include/xieite/traits/convertible_to_any.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct ConvertibleToAny
: std::bool_constant<xieite::concepts::ConvertibleToAny<Source, Targets...>> {};
```
