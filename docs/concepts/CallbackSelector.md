# `xieite::concepts::CallbackSelector`
Defined in header [`<xieite/concepts/CallbackSelector.hpp>`](../../include/xieite/concepts/CallbackSelector.hpp)

<br/>


Specifies that type `Invocable` is a comparator callback which accepts an `Argument` and returns a `bool`-like.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Invocable, typename Argument>
concept CallbackSelector = std::convertible_to<std::invoke_result_t<Invocable, Argument>, bool>;
```
### Template parameters
- `Incvocable` - Any type
- `Argument` - Any type
