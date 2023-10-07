# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsBaseOfAllOf
Defined in header [<xieite/traits/IsBaseOfAllOf.hpp>](../../../include/xieite/traits/IsBaseOfAllOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Base, typename... Derived>
struct IsBaseOfAllOf
: std::bool_constant<xieite::concepts::BaseOfAllOf<Base, Derived...>> {};
```
