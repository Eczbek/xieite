# [xieite](../xieite.md)\:\:[math](../math.md)\:\:antimodes
Defined in header [<xieite/math/antimodes.hpp>](../../include/xieite/math/antimodes.hpp)

&nbsp;

## Description
Computes the antimodes of some values. Returns `{ 0 }` if no arguments are passed.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric... Numbers>
[[nodiscard]] constexpr std::vector<xieite::math::Result<Numbers...>> antimodes(const Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/antimodes.hpp>

int main() {
    for (int value : xieite::math::antimodes(1, 3, 2, 4, 5)) {
        std::cout << value << '\n';
    }
}
```
Output:
```
1
2
```
