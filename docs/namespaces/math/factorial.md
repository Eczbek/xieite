# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:factorial\<\>
Defined in header [<xieite/math/factorial.hpp>](../../../include/xieite/math/factorial.hpp)

&nbsp;

## Description
A lookup table of all representable factorial values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
inline constexpr std::array<Arithmetic_, /* size */> factorial = /* ... */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/factorial.hpp"

int main() {
    std::println("{}", xieite::math::factorial<std::size_t>[17]);
}
```
Output:
```
355687428096000
```
