# xieite::concepts::ComparatorCallback
Defined in header `<xieite/concepts/ComparatorCallback.hpp>`

<br/>

Specifies that type `Invocable` is a comparator callback which accepts two `Argument`s and returns a `bool`-like.

<br/><br/>

## Declarations
```cpp
template<typename Invocable, typename Argument>
concept ComparatorCallback = std::convertible_to<std::invoke_result_t<Invocable, Argument, Argument>, bool>;
```
