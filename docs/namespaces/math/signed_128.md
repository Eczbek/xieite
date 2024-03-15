# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Signed128
Defined in header [<xieite/math/signed_128.hpp>](../../../include/xieite/math/signed_128.hpp)

&nbsp;

## Description
A type alias to a compiler-specific extension for a signed 128-bit integer.

&nbsp;

## Synopsis
#### 1)
```cpp
using Signed128 = /* ... */
```

&nbsp;

## Example
```cpp
#include <limits>
#include <print>
#include "xieite/math/signed_128.hpp"

int main() {
    xieite::math::Signed128 foo = std::numeric_limits<std::uint64_t>::max();

    std::println("{}", foo);

    std::println("{}", foo * -397846);
}
```
Possible output:
```
18446744073709551615
-7338963342749050271821290
```
