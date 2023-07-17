# [xieite](../xieite.md)::[traits](../traits.md)::isFunctable
Defined in header [<xieite/traits/isFunctable.hpp>](../../include/xieite/traits/isFunctable.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename, typename>
inline constexpr bool isFunctable = false;
```
### Template parameters
- Unconstrained parameter
- Unconstrained parameter

<br/><br/>

```cpp
template<typename Functor, typename Result, typename... Parameters>
inline constexpr bool isFunctable<Functor, Result(Parameters...)> = std::same_as<Result, decltype(std::declval<Functor>()(std::declval<Parameters>()...))>;
```
### Template parameters
- `Functor` - Any type
- `Result` - Any type
- `Parameters...` - Any types

<br/><br/>

```cpp
template<typename Functor, typename Result, typename... Parameters>
inline constexpr bool isFunctable<Result(Parameters...), Functor> = xieite::traits::isFunctable<Functor, Result(Parameters...)>;
```
### Template parameters
- `Functor` - Any type
- `Result` - Any type
- `Parameters...` - Any types
