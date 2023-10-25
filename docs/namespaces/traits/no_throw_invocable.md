# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:NoThrowInvocable
Defined in header [<xieite/traits/no_throw_invocable.hpp>](../../../include/xieite/traits/no_throw_invocable.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Functor, typename... Arguments>
struct NoThrowInvocable
: std::bool_constant<xieite::concepts::NoThrowInvocable<Functor, Arguments...>> {};
```
