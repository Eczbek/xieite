# xieite::concepts::Decayed
Defined in header `<xieite/concepts/Decayed.hpp>`

<br/><br/>

## Declarations
```cpp
template<typename Any>
concept Decayed = std::same_as<Any, std::decay_t<Any>>;
```
