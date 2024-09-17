# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:modes\<\>\(\)
Defined in fragment [xieite:math.modes](../../../src/math/modes.cpp)

&nbsp;

## Description
Finds values which are greater than both their direct neighbors.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::range_value_t<Range>> modes(Range&& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
requires(!!sizeof...(Number))
[[nodiscard]] constexpr std::vector<std::common_type_t<double, Arithmetics...>> modes(Arithmetics... values) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    for (int value : xieite::math::modes(1, 3, 2, 4, 5)) {
        std::println("{}", value);
    }
}
```
Output:
```
3
5
```
