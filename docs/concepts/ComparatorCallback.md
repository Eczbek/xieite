# xieite::concepts::ComparatorCallback
Defined in header `<xieite/concepts/ComparatorCallback.hpp>`

<br/>

Specifies that type `T` is a comparator callback which accepts two `U`s.

<br/><br/>

## Declarations
```cpp
template<typename T, typename U>
concept ComparatorCallback = std::convertible_to<std::invoke_result_t<T, U, U>, bool>;
```
