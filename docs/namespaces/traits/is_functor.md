# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsFunctor\<\> \{\}
Defined in header [<xieite/traits/is_functor.hpp>](../../../include/xieite/traits/is_functor.hpp)

&nbsp;

## [Description](../concepts/functor.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename, typename>
struct IsFunctor
: std::false_type {};
```
#### 2)
```cpp
template<typename Functor, typename Return, typename... Arguments>
struct IsFunctor<Functor, Return(Arguments...)>
: std::bool_constant</* ... */> {};
```

&nbsp;

## [Example](../concepts/functor.md#Example)
