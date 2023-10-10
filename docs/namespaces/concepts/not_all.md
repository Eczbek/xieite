# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NotAll
Defined in header [<xieite/concepts/not_all.hpp>](../../../include/xieite/concepts/not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept NotAll = !xieite::concepts::All<Type, Traits...>;
```
