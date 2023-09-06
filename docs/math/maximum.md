# [xieite](../xieite.md)\:\:[math](../math.md)\:\:maximum
Defined in header [<xieite/math/maximum.hpp>](../../include/xieite/math/maximum.hpp)

&nbsp;

## Description
Computes the maximum of some values. Returns `0` if no arguments are passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric... Numbers>
constexpr xieite::math::Result<Numbers...> maximum(const Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/maximum.hpp>

int main() {
    std::cout << xieite::math::maximum(1, 3, 2, 4, 5) << '\n';
}
```
Output:
```
5
```
