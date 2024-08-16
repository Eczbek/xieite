# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:minimum\<\>\(\)
Defined in header [<xieite/math/minimum.hpp>](../../../include/xieite/math/minimum.hpp)

&nbsp;

## Description
Computes the minimum of some values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
requires(sizeof...(Arithmetics) > 0)
[[nodiscard]] constexpr std::common_type_t<Arithmetics...> minimum(Arithmetics... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/minimum.hpp"

int main() {
    std::println("{}", xieite::math::minimum(1, 3, 2, 4, 5));
}
```
Output:
```
1
```
