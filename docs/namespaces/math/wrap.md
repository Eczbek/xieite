# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:wrap\<\>\(\)
Defined in header [<xieite/math/wrap.hpp>](../../../include/xieite/math/wrap.hpp)

&nbsp;

## Description
"Wraps" a number between two limits, inclusively.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ wrap(Arithmetic_ value, Arithmetic_ limit1, Arithmetic_ limit2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/wrap.hpp"

int main() {
    for (int i = 0; i < 10; ++i) {
        std::println("{}", xieite::math::wrap(i, 4, -2));
    }
}
```
Output:
```
0
1
2
3
4
-2
-1
0
1
2
```
