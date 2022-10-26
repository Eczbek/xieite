# xieite::concepts::Comparator
Declared in `<xieite/concepts/Comparator.hpp>`
```cpp
template<typename T, typename U>
concept Comparator = std::convertible_to<std::invoke_result_t<T, const U&, const U&>, bool>;
```
Specifies that a type `T` is a comparator callback.
