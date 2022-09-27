# gcufl::concepts::Trivial
Declared in `<gcufl/concepts/Trivial.hpp>`
```cpp
template<typename T>
concept Trivial = std::is_trivial_v<T>;
```
Specifies that a type `T` is trivial.