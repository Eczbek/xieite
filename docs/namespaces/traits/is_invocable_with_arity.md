# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsInvocableWithArity\<\> \{\}
Defined in header [<xieite/traits/is_invocable_with_arity.hpp>](../../../include/xieite/traits/is_invocable_with_arity.hpp)

&nbsp;

## [Description](../concepts/invocable_with_arity.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor_, std::size_t arity_>
struct IsInvocableWithArity
: std::bool_constant<xieite::concepts::InvocableWithArity<Functor_, arity_>> {};
```

&nbsp;

## [Example](../concepts/invocable_with_arity.md#Example)
