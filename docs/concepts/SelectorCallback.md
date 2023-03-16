# xieite::concepts::SelectorCallback
Defined in header `<xieite/concepts/SelectorCallback.hpp>`

<br/>

Specifies that type `Invocable` is a comparator callback which accepts an `Argument` and returns a `bool`-like.

<br/><br/>

## Declarations
```cpp
template<typename Invocable, typename Argument>
concept SelectorCallback = std::convertible_to<std::invoke_result_t<Invocable, Argument>, bool>;
```
