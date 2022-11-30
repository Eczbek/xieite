# xieite::concepts::UniformRandomGenerator
Declared in `<xieite/concepts/UniformRandomGenerator.hpp>`

<br/><br/>

## Declaration
```cpp
template<typename T>
concept UniformRandomGenerator = std::uniform_random_bit_generator<std::remove_reference_t<T>>;
```
