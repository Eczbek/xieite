# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:UniformRandomBitGenerator\<\>
Defined in header [<xieite/concepts/uniform_random_bit_generator.hpp>](../../../include/xieite/uniform_random_bit_generator.hpp)

&nbsp;

## Description
Specifies that a type is a uniform random bit generator.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept UniformRandomBitGenerator = std::uniform_random_bit_generator<std::remove_reference_t<Type>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <random>
#include "xieite/concepts/uniform_random_bit_generator.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::UniformRandomBitGenerator<std::mt19937>);
    std::println("{}", xieite::concepts::UniformRandomBitGenerator<Nope>);
}
```
Output:
```
true
false
```
