# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../integer.md)\:\:Integer\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Constructs a `xieite::math::Integer<bits, sign>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral OtherInteger = int>
constexpr Integer(OtherInteger value = 0) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", xieite::math::Integer<6, false>(418).data());
}
```
Output:
```
34
```
