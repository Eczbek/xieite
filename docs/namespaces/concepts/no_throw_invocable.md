# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowInvocable
Defined in header [<xieite/concepts/no_throw_invocable.hpp>](../../../include/xieite/concepts/no_throw_invocable.hpp)

&nbsp;

## Description
Specifies that a functor can be invoked without throwing exceptions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Functor, typename... Arguments>
concept NoThrowInvocable = std::invocable<Functor, Arguments...> && noexcept(std::declval<Functor>()(std::declval<Arguments>()...));
```
