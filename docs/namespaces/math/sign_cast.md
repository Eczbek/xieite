# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:signCast\<\>\(\)
Defined in header [<xieite/math/sign_cast.hpp>](../../../include/xieite/math/sign_cast.hpp)

&nbsp;

## Description
Casts a value to the signedness of the target type before converting the value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Target_, std::integral Source_>
[[nodiscard]] constexpr Target_ signCast(Source_ value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/math/sign_cast.hpp"

int main() {
    std::int8_t foo = -1;

    std::uint64_t bar = static_cast<std::uint64_t>(foo);

    std::uint64_t baz = xieite::math::signCast<std::uint64_t>(foo);

    std::println("{}", bar);
    std::println("{}", baz);
}
```
Output:
```
18446744073709551615
255
```
