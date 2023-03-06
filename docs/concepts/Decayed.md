# xieite::concepts::Decayed
Defined in header `<xieite/concepts/Decayed.hpp>`

<br/><br/>

## Declarations
```cpp
template<typename T>
concept Decayed = std::same_as<T, std::decay_t<T>>;
```
