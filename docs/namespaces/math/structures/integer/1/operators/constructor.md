# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../integer.md)\:\:Integral\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Constructs a `xieite::math::Integer<bits_, sign_>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral OtherIntegral = int>
constexpr Integral(OtherIntegral value = 0) noexcept;
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
