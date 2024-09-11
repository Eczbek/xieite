# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:subtractionOverflows\<\>\(\)
Defined in fragment [xieite:math.subtractionOverflows](../../../src/math/subtraction_overflows.cpp)

&nbsp;

## Description
Checks if the subtraction of multiple values will overflow or underflow their type, or is not representable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
[[nodiscard]] constexpr bool subtractionOverflows(First first, const Rest... rest) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::subtractionOverflows<std::uint8_t>(4, 90));
}
```
Output:
```
true
```
