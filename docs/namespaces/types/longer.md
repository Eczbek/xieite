# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Longer
Defined in header [<xieite/types/longer.hpp>](../../../include/xieite/types/longer.hpp)

&nbsp;

## Description
Gets the next larger number type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Type>
requires(!std::same_as<std::remove_cvref_t<Type>, std::float128_t>)
using Longer = xieite::types::List<std::uint8_t, std::uint16_t, std::int16_t, std::uint32_t, std::int32_t, std::uint64_t, std::int64_t, xieite::math::Unsigned128, xieite::math::Signed128, std::float16_t, std::float32_t, std::float64_t, long double, std::float128_t>::At<xieite::types::List<bool, std::uint8_t, std::int8_t, std::uint16_t, std::int16_t, std::uint32_t, std::int32_t, std::uint64_t, std::int64_t, std::bfloat16_t, std::float16_t, std::float32_t, std::float64_t, long double>::find<std::remove_cvref_t<Type>>>;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <cstdint>
#include <print>
#include "xieite/types/longer.hpp"

int main() {
    using A = std::uint8_t;
    using B = xieite::types::Longer<A>;
    using C = xieite::types::Longer<B>;
    using D = xieite::types::Longer<C>;

    std::println("{}", std::same_as<B, std::uint16_t>);
    std::println("{}", std::same_as<C, std::uint32_t>);
    std::println("{}", std::same_as<D, std::uint64_t>);
}
```
Possible output:
```
true
true
true
```
