# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsInvocable\<\> \{\}
Defined in fragment [xieite:traits.IsInvocable](../../../src/traits/is_invocable.cpp)

&nbsp;

## [Description](../concepts/invocable.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename, typename>
struct IsInvocable
: std::false_type {};
```
#### 2)
```cpp
template<typename Type, typename Return, typename... Arguments>
struct IsInvocable<Type, Return(Arguments...)>
: std::is_invocable_r<Return, Type, Arguments...> {};
```

&nbsp;

## [Example](../concepts/invocable.md#Example)
