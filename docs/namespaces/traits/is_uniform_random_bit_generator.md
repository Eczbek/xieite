# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsUniformRandomBitGenerator
Defined in header [<xieite/traits/is_uniform_random_bit_generator.hpp>](../../../include/xieite/uniform_random_bit_generator.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsUniformRandomBitGenerator
: std::bool_constant<xieite::concepts::UniformRandomBitGenerator<Type>> {};
```
