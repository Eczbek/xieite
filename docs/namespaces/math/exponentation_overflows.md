# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:exponentationOverflows\<\>\(\)
Defined in fragment [xieite:math.exponentationOverflows](../../../src/math/exponentation_overflows.cpp)

&nbsp;

## Description
Checks if the power of a base to any number of exponents will overflow its type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
[[nodiscard]] constexpr bool exponentiationOverflows(First first, const Rest... rest) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::print("{}", xieite::math::exponentationOverflows<std::uint8_t>(2, 9));
}
```
Output:
```
true
```
