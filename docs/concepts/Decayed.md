# xieite::concepts::Decayed
Declared in `<xieite/concepts/Decayed.hpp>`

<br/><br/>

## Declaration
```cpp
template<typename T>
concept Decayed = std::same_as<T, std::decay_t<T>>;
```
