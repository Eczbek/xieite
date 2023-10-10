# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:Any
Defined in header [<xieite/traits/any.hpp>](../../../include/xieite/traits/any.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct Any
: std::bool_constant<xieite::concepts::Any<Type, Traits...>> {};
```
