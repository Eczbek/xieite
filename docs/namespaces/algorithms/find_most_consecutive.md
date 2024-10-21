# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:findMostConsecutive\<\>\(\)
Defined in fragment [xieite:algorithms.findMostConsecutive](../../../src/algorithms/find_most_consecutive.cpp)

&nbsp;

## Description
Finds the subrange of greatest length containing the maximum number of consecutive values. If no matching values are found, returns a subrange where both iterators are set to the range's end.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Functor = std::ranges::equal_to>
requires(std::ranges::sized_range<Range>)
[[nodiscard]] constexpr auto findMostConsecutive(Range& range, const std::ranges::range_common_reference_t<Range> value, Functor&& comparator = Functor())
XIEITE_ARROW(xieite::algorithms::getMostConsecutive(/* ... */))
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    //               indices: 0  1  2  3  4  5  6  7
    std::vector<int> values { 1, 0, 1, 1, 1, 0, 1, 1 };
    //           consecutive: 1     1  2  3     1  2

    auto result = xieite::algorithms::findMostConsecutive(values, 1);

    std::println("{} - {}", std::ranges::distance(values.begin(), result.begin()), std::ranges::distance(values.begin(), result.end()));
}
```
Output:
```
2 - 5
```
