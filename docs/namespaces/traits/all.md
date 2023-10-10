# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:All
Defined in header [<xieite/traits/all.hpp>](../../../include/xieite/traits/all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct All
: std::bool_constant<xieite::concepts::All<Type, Traits...>> {};
```
