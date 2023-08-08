# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:UniformRandomBitGenerator
Defined in header [<xieite/concepts/UniformRandomBitGenerator.hpp>](../../include/xieite/UniformRandomBitGenerator.hpp)

&nbsp;

## Description
Specifies that a type is a uniform random bit generator.

&nbsp;

## Synopsis
```cpp
template<typename Type>
concept UniformRandomBitGenerator = std::uniform_random_bit_generator<std::remove_reference_t<Type>>;
```
