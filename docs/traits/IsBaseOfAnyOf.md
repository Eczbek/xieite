# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsBaseOfAnyOf
Defined in header [<xieite/traits/IsBaseOfAnyOf.hpp>](../../include/xieite/traits/IsBaseOfAnyOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsBaseOfAnyOf
: std::bool_constant<xieite::concepts::BaseOfAnyOf<Source, Targets...>> {};
```
