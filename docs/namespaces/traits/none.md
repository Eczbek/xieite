# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:None
Defined in header [<xieite/traits/none.hpp>](../../../include/xieite/traits/none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct None
: std::bool_constant<xieite::concepts::None<Type, Traits...>> {};
```
