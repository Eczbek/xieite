# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:exponentationOverflows\<\>\(\)
Defined in header [<xieite/math/exponentation_overflows.hpp>](../../../include/xieite/math/exponentation_overflows.hpp)

&nbsp;

## Description
Checks if the power of a base to an exponent will overflow its type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr bool exponentationOverflows(Arithmetic_ base, Arithmetic_ exponent) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/math/exponentation_overflows.hpp"

int main() {
    std::print("{}", xieite::math::exponentationOverflows<std::uint8_t>(2, 9));
}
```
Output:
```
true
```
