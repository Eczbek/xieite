# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:multiplicationOverflows\<\>\(\)
Defined in fragment [xieite:math.multiplicationOverflows](../../../src/math/multiplication_overflows.cpp)

&nbsp;

## Description
Checks if the multiplication of two values will overflow or underflow their type, or is not representable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool multiplicationOverflows(Arithmetic multiplier, Arithmetic multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::multiplicationOverflows<std::uint8_t>(99, 99));
}
```
Output:
```
true
```
