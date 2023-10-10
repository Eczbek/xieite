# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNone
Defined in header [<xieite/traits/is_none.hpp>](../../../include/xieite/traits/is_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsNone
: std::bool_constant<xieite::concepts::None<Type, Traits...>> {};
```
