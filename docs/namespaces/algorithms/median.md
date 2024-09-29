# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:median\<\>\(\)
Defined in fragment [xieite:algorithms.median](../../../src/algorithms/median.cpp)

&nbsp;

## Description
Computes the median of some values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range>
requires(std::ranges::sized_range<Range> && xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> median(Range&& range) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::array<int, 5> data = { 1, 1, 2, 2, 5 };

    std::println("{}", xieite::algorithms::median(data));
}
```
Output:
```
2
```
