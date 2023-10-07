# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAllOf
Defined in header [<xieite/traits/IsSameAsAllOf.hpp>](../../../include/xieite/traits/IsSameAsAllOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsAllOf
: std::bool_constant<xieite::concepts::SameAsAllOf<Source, Targets...>> {};
```
