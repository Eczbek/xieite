# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:NotAll
Defined in header [<xieite/traits/not_all.hpp>](../../../include/xieite/traits/not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct NotAll
: std::bool_constant<xieite::concepts::NotAll<Type, Traits...>> {};
```
