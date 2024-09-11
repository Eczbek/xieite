# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:additionOverflows\<\>\(\)
Defined in fragment [xieite:math.additionOverflows](../../../src/math/addition_overflows.cpp)

&nbsp;

## Description
Checks if the addition of multiple values will overflow or underflow their type (therefore causing undefined behavior with signed integers), or is not representable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
[[nodiscard]] constexpr bool additionOverflows(First first, const Rest... rest) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::print("{}", xieite::math::additionOverflows<std::int8_t>(127, 1));
}
```
Output:
```
true
```
