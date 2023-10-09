# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAllOf
Defined in header [<xieite/traits/is_all_of.hpp>](../../../include/xieite/traits/is_all_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsAllOf
: std::bool_constant<xieite::concepts::AllOf<Type, Traits...>> {};
```
