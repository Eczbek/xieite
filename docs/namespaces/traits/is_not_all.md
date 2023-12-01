# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNotAll
Defined in header [<xieite/traits/is_not_all.hpp>](../../../include/xieite/traits/is_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsNotAll
: std::bool_constant<xieite::concepts::NotAll<Type, Traits...>> {};
```
