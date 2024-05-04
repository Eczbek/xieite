# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:round\<\>\(\)
Defined in header [<xieite/math/round.hpp>](../../../include/xieite/math/round.hpp)

&nbsp;

## Description
Rounds a value to the nearest multiple of a step.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ round(Arithmetic_ value, Arithmetic_ step = 1) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/round.hpp"

int main() {
    std::println("{}", xieite::math::round(17, 5));
}
```
Output:
```
20
```
