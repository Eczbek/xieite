# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:mean\<\>\(\)
Defined in fragment [xieite:math.mean](../../../src/math/mean.cpp)

&nbsp;

## Description
Computes the mean of some values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range>
requires(xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> mean(Range&& range) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
requires(!!sizeof...(Arithmetics))
[[nodiscard]] constexpr std::common_type_t<double, Arithmetics...> mean(Arithmetics... values) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::mean(1, 1, 2, 2, 5));
}
```
Output:
```
2.2
```
