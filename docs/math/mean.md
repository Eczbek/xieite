# [xieite](../xieite.md)\:\:[math](../math.md)\:\:mean
Defined in header [<xieite/math/mean.hpp>](../../include/xieite/math/mean.hpp)

&nbsp;

## Description
Computes the mean of some values. Returns `0` if no arguments are passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric... Numbers>
[[nodiscard]] constexpr xieite::math::Result<Numbers...> mean(const Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/mean.hpp>

int main() {
    std::cout << xieite::math::mean(1, 1, 2, 2, 5) << '\n';
}
```
Output:
```
2.2
```
