# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:fibonacci\<\>
Defined in header [<xieite/math/fibonacci.hpp>](../../../include/xieite/math/fibonacci.hpp)

&nbsp;

## Description
A lookup table of all representable values of the fibonacci sequence.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
inline constexpr std::array<Arithmetic_, /* size */> fibonacci = /* ... */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/fibonacci.hpp"

int main() {
    std::println("{}", xieite::math::fibonacci<std::size_t>[45]);
}
```
Output:
```
1134903170
```
