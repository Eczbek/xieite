# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowInvocable\<\> \{\}
Defined in fragment [xieite:traits.IsNoThrowInvocable](../../../src/traits/is_no_throw_invocable.cpp)

&nbsp;

## [Description](../concepts/no_throw_invocable.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename, typename>
struct IsNoThrowInvocable
: std::false_type {};
```
#### 2)
```cpp
template<typename Type, typename Return, typename... Arguments>
struct IsNoThrowInvocable<Type, Return(Arguments...)>
: std::is_nothrow_invocable_r<Return, Type, Arguments...> {};
```

&nbsp;

## [Example](../concepts/no_throw_invocable.md#Example)
