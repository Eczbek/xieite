# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsInvocableWithArity\<\> \{\}
Defined in header [<xieite/traits/is_invocable_with_arity.hpp>](../../../include/xieite/traits/is_invocable_with_arity.hpp)

&nbsp;

## [Description](../concepts/invocable_with_arity.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor, std::size_t arity>
struct IsInvocableWithArity
: std::bool_constant<xieite::concepts::InvocableWithArity<Functor, arity>> {};
```

&nbsp;

## [Example](../concepts/invocable_with_arity.md#Example)
