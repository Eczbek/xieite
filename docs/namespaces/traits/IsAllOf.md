# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAllOf
Defined in header [<xieite/traits/IsAllOf.hpp>](../../../include/xieite/traits/IsAllOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsAllOf
: std::bool_constant<xieite::concepts::AllOf<Type, Traits...>> {};
```
