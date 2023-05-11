# [`xieite`](../../README.md)`::`[`traits`](../../docs/traits.md)`::isFunction`
Defined in header [`<xieite/traits/isFunction.hpp>`](../../include/xieite/traits/isFunction.hpp)

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename, typename>
constexpr bool isFunction = false;
```
### Template parameters
- Unconstrained parameter
- Unconstrained parameter

<br/><br/>

```cpp
template<typename Result, typename... Parameters, std::invocable<Parameters...> Invocable>
constexpr bool isFunction<Invocable, Result(Parameters...)> = std::convertible_to<std::invoke_result_t<Invocable, Parameters...>, Result>;
```
### Template parameters
- `Result` - Any type
- `Parameters...` - Any types
- `Invocable` - A type invocable with `Parameters...`
