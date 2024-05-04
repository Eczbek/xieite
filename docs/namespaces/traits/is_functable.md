# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsFunctable\<\> \{\}
Defined in header [<xieite/traits/is_functable.hpp>](../../../include/xieite/traits/is_functable.hpp)

&nbsp;

## [Description](../concepts/functable.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename, typename>
struct IsFunctable
: std::false_type {};
```
#### 2)
```cpp
template<typename Functor_, typename Return_, typename... Arguments_>
struct IsFunctable<Functor_, Return_(Arguments_...)>
: std::bool_constant</* ... */> {};
```

&nbsp;

## [Example](../concepts/functable.md#Example)
