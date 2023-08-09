# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsAnyOf
Defined in header [<xieite/traits/IsAnyOf.hpp>](../../include/xieite/traits/IsAnyOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsAnyOf
: std::bool_constant<xieite::concepts::AnyOf<Type, Traits...>> {};
```
