# xieite::concepts::Decayed
Declared in `<xieite/concepts/Decayed.hpp>`
```cpp
template<typename T>
concept Decayed = std::is_same_v<T, std::decay_t<T>>;
```
Specifies that a type `T` is decayed.
