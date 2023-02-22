# xieite::concepts::Comparator
Defined in header `<xieite/concepts/Comparator.hpp>`

<br/>

Specifies that type `T` is a comparator callback.

<br/><br/>

## Declaration
```cpp
template<typename T, typename U>
concept Comparator = std::convertible_to<std::invoke_result_t<T, U&&, U&&>, bool>;
```
