# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:ceiling\<\>\(\)
Defined in header [<xieite/math/ceiling.hpp>](../../../include/xieite/math/ceiling.hpp)

&nbsp;

## Description
Rounds a value up to the next multiple of a step.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ ceiling(Arithmetic_ value, Arithmetic_ step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/ceiling.hpp"

int main() {
    std::println("{}", xieite::math::ceiling(17, 8));
}
```
Output:
```
24
```
