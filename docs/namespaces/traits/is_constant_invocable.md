# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConstantInvocable
Defined in header [<xieite/traits/is_constant_invocable.hpp"](../../../include/xieite/traits/is_constant_invocable.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Functor, typename... Arguments>
struct IsConstantInvocable
: std::bool_constant<xieite::concepts::ConstantInvocable<Functor, Arguments...>> {};
```
