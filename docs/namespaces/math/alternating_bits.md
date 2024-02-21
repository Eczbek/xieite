# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:alternatingBits
Defined in header [<xieite/math/alternating_bits.hpp"](../../../include/xieite/math/alternating_bits.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
inline constexpr Integer alternatingBits = std::numeric_limits<Integer>::max() / 3;
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <cstdint>
#include <iostream>
#include "xieite/math/alternating_bits.hpp"

int main() {
    std::bitset<32> bits = xieite::math::alternatingBits<std::uint32_t>;

    std::cout << bits << '\n';
}
```
Output:
```
01010101010101010101010101010101
```
