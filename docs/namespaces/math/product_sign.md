# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:productSign\<\>\(\)
Defined in header [<xieite/math/product_sign.hpp>](../../../include/xieite/math/product_sign.hpp)

&nbsp;

## Description
Gets the sign of the product of multiple numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics_>
[[nodiscard]] constexpr int productSign(Arithmetics_... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/sign.hpp"

int main() {
    std::println("{}", xieite::math::productSign(2, -4, -8));
}
```
Output:
```
1
```
