# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConstantInvocable
Defined in header [<xieite/concepts/constant_invocable.hpp>](../../../include/xieite/concepts/constant_invocable.hpp)

&nbsp;

## Description
Specifies that a type is invokable without mutating.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Functor, typename... Arguments>
concept ConstantInvocable = std::invocable<Functor, Arguments...> && requires(const Functor functor, Arguments... arguments) {
	std::invoke(functor, std::forward<Arguments>(arguments)...);
};
```
