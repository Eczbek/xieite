# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsConstantInvocable \{\}
Defined in header [<xieite/traits/is_constant_invocable.hpp>](../../../include/xieite/traits/is_constant_invocable.hpp)

&nbsp;

## [Description](../concepts/constant_invocable.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Functor_, typename... Arguments_>
struct IsConstantInvocable
: std::bool_constant<xieite::concepts::ConstantInvocable<Functor_, Arguments_...>> {};
```

&nbsp;

## [Example](../concepts/constant_invocable.md#Example)
