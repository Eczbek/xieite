# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:None
Defined in header [<xieite/concepts/none.hpp>](../../../include/xieite/concepts/none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept None = !xieite::concepts::Any<Type, Traits...>;
```
