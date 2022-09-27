# gcufl::concepts::Comparator
Declared in `<gcufl/concepts/Comparator.hpp>`
```cpp
template<typename T, typename U>
concept Comparator = std::convertible_to<std::invoke_result<T(U, U)>, bool>;
```
Specifies that a type `T` is a comparator callback.
