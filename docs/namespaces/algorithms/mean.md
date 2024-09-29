# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:mean\<\>\(\)
Defined in fragment [xieite:algorithms.mean](../../../src/algorithms/mean.cpp)

&nbsp;

## Description
Computes the mean of some values.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range>
requires(std::ranges::sized_range<Range> && xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::common_type_t<double, std::ranges::range_value_t<Range>> mean(Range&& range) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::array<int, 5> data = { 1, 1, 2, 2, 5 };

    std::println("{}", xieite::algorithms::mean(data));
}
```
Output:
```
2.2
```
