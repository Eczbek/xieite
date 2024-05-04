# [xieite](../../xieite.md)\:\:[random](../../random.md)\:\:UniformDistribution\<\>
Defined in header [<xieite/random/uniform_distribution.hpp>](../../../include/xieite/random/uniform_distribution.hpp)

&nbsp;

## Description
A type alias to a uniform distribution for an integer, boolean, or floating point.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
using UniformDistribution = std::conditional_t<std::integral<Arithmetic_>, std::conditional_t<std::same_as<Arithmetic_, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Arithmetic_>>, std::uniform_real_distribution<Arithmetic_>>;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include <random>
#include "xieite/concepts/specialization_of.hpp"
#include "xieite/random/uniform_distribution.hpp"

int main() {
    using Foo = xieite::random::UniformDistribution<int>;
    using Bar = xieite::random::UniformDistribution<bool>;
    using Baz = xieite::random::UniformDistribution<double>;

    std::println("{}", xieite::concepts::SpecializationOf<Foo, std::uniform_int_distribution>);
    std::println("{}", std::same_as<Bar, std::bernoulli_distribution>);
    std::println("{}", xieite::concepts::SpecializationOf<Baz, std::uniform_real_distribution>);
}
```
Output:
```
true
true
true
```
