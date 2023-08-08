# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:isFunctable
Defined in header [<xieite/traits/isFunctable.hpp>](../../include/xieite/traits/isFunctable.hpp)

&nbsp;

## Synopses

&nbsp;

```cpp
template<typename, typename>
inline constexpr bool isFunctable = false;
```
#### Template parameters
- Unconstrained parameter
- Unconstrained parameter

&nbsp;

```cpp
template<typename Functor, typename Result, typename... Arguments>
inline constexpr bool isFunctable<Functor, Result(Arguments...)> = std::same_as<Result, decltype(std::declval<Functor>()(std::declval<Arguments>()...))>;
```
#### Template parameters
- `Functor` - Any type
- `Result` - Any type
- `Arguments...` - Any types

&nbsp;

```cpp
template<typename Functor, typename Result, typename... Arguments>
inline constexpr bool isFunctable<Result(Arguments...), Functor> = xieite::traits::isFunctable<Functor, Result(Arguments...)>;
```
#### Template parameters
- `Functor` - Any type
- `Result` - Any type
- `Arguments...` - Any types
