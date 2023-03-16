# xieite::concepts::UniformRandomBitGenerator
Defined in header `<xieite/concepts/UniformRandomBitGenerator.hpp>`

<br/><br/>

## Declarations
```cpp
template<typename Any>
concept UniformRandomBitGenerator = std::uniform_random_bit_generator<std::remove_reference_t<Any>>;
```
