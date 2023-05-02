# [`xieite`](../../README.md)`::`[`concepts`](../../docs/concepts.md)`::CallbackComparator`
Defined in header [`<xieite/concepts/CallbackComparator.hpp>`](../../include/xieite/concepts/CallbackComparator.hpp)

<br/>

Specifies that type `Invocable` is a comparator callback which accepts two `Argument`s and returns a `bool`-like.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<typename Invocable, typename Argument>
concept CallbackComparator = std::convertible_to<std::invoke_result_t<Invocable, Argument, Argument>, bool>;
```
### Template parameters
- `Invocable` - Any type
- `Argument` - Any type
