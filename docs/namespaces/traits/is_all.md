# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAll
Defined in header [<xieite/traits/is_all.hpp"](../../../include/xieite/traits/is_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsAll
: std::bool_constant<xieite::concepts::All<Type, Traits...>> {};
```
