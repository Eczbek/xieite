# xieite::concepts::UniformRandomGenerator
Declared in `<xieite/concepts/UniformRandomGenerator.hpp>`
```cpp
template<typename T>
concept UniformRandomGenerator = std::uniform_random_bit_generator<std::remove_reference_t<T>>;
```
Specifies that a type `T` is a uniform random bit generator.
