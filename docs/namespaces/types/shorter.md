# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Shorter
Defined in header [<xieite/types/shorter.hpp>](../../../include/xieite/types/shorter.hpp)

&nbsp;

## Description
Gets the next smaller number type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
requires((xieite::concepts::Numeric<Type> || xieite::concepts::SameAsAny<std::remove_cvref_t<Type>, xieite::math::Unsigned128, xieite::math::Signed128>) && !std::same_as<std::remove_cvref_t<Type>, std::bfloat16_t>)
using Shorter = xieite::types::List<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, bool, bool, long double, std::float64_t, std::float32_t, std::float16_t, std::bfloat16_t>::At<xieite::types::List<xieite::math::Unsigned128, xieite::math::Signed128, std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, std::float128_t, long double, std::float64_t, std::float32_t, std::float16_t>::find<std::remove_cvref_t<Type>>>;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <cstdint>
#include <print>
#include "xieite/types/shorter.hpp"

int main() {
    using A = std::uint64_t;
    using B = xieite::types::Shorter<A>;
    using C = xieite::types::Shorter<B>;
    using D = xieite::types::Shorter<C>;

    std::println("{}", std::same_as<B, std::uint32_t>);
    std::println("{}", std::same_as<C, std::uint16_t>);
    std::println("{}", std::same_as<D, std::uint8_t>);
}
```
Possible output:
```
true
true
true
```
