# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowInvocableWithArity\<\> \{\}
Defined in header [<xieite/traits/is_no_throw_invocable_with_arity.hpp>](../../../include/xieite/traits/is_no_throw_invocable_with_arity.hpp)

&nbsp;

## [Description](../concepts/no_throw_invocable_with_arity.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor_, std::size_t arity_>
struct IsNoThrowInvocableWithArity
: std::bool_constant<xieite::concepts::NoThrowInvocableWithArity<Functor_, arity_>> {};
```

&nbsp;

## [Example](../concepts/no_throw_invocable_with_arity.md#Example)
