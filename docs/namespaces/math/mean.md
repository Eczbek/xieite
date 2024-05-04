# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:mean\<\>\(\)
Defined in header [<xieite/math/mean.hpp>](../../../include/xieite/math/mean.hpp)

&nbsp;

## Description
Computes the mean of some values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range_>>)
[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range_>> mean(Range_&& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics_>
requires(sizeof...(Arithmetics_) > 0)
[[nodiscard]] constexpr std::common_type_t<double, Arithmetics_...> mean(Arithmetics_... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/mean.hpp"

int main() {
    std::println("{}", xieite::math::mean(1, 1, 2, 2, 5));
}
```
Output:
```
2.2
```
