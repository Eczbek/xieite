# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:maximum\<\>\(\)
Defined in header [<xieite/math/maximum.hpp>](../../../include/xieite/math/maximum.hpp)

&nbsp;

## Description
Finds the maximum of several values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics_>
requires(sizeof...(Arithmetics_) > 0)
[[nodiscard]] constexpr std::common_type_t<Arithmetics_...> maximum(Arithmetics_... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/maximum.hpp"

int main() {
    std::println("{}", xieite::math::maximum(1, 3, 2, 4, 5));
}
```
Output:
```
5
```
