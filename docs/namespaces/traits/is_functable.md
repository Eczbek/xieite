# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsFunctable
Defined in header [<xieite/traits/is_functable.hpp"](../../../include/xieite/traits/is_functable.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename, typename>
struct IsFunctable
: std::false_type {};
```
#### 2)
```cpp
template<typename Functor, typename Result, typename... Arguments>
struct IsFunctable<Functor, Result(Arguments...)>
: std::bool_constant<requires(Functor functor, Arguments... arguments) {
    { std::invoke(functor, arguments...) } -> std::convertible_to<Result>;
}> {};
```
