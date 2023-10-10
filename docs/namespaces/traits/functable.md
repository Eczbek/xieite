# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:Functable
Defined in header [<xieite/traits/functable.hpp>](../../../include/xieite/traits/functable.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename, typename>
struct Functable
: std::false_type {};
```
#### 2)
```cpp
template<typename Functor, typename Result, typename... Arguments>
struct Functable<Functor, Result(Arguments...)>
: std::bool_constant<requires(Functor functor, Arguments... arguments) {
    { std::invoke(functor, arguments...) } -> std::convertible_to<Result>;
}> {};
```
