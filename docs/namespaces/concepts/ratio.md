# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Ratio
Defined in header [<xieite/concepts/ratio.hpp"](../../../include/xieite/concepts/ratio.hpp)

&nbsp;

## Description
Specifies that a type satisfies `std::ranges::range` and contains values of a specified type. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Ratio = xieite::traits::IsRatio<std::remove_cv_t<Type>>::value;
```

&nbsp;

## Example
```cpp
#include <print>
#include <ratio>
#include "xieite/concepts/ratio.hpp"

struct Nope {};

int main() {
    std::println("{}", xieite::concepts::Ratio<std::centi>);
    std::println("{}", xieite::concepts::Ratio<Nope>);
}
```
Output:
```
true
false
```
