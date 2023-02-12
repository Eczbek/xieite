# xieite::concepts::UniformRandomBitGenerator
Declared in `<xieite/concepts/UniformRandomBitGenerator.hpp>`

<br/><br/>

## Declaration
```cpp
template<typename T>
concept UniformRandomBitGenerator = std::uniform_random_bit_generator<std::remove_reference_t<T>>;
```
