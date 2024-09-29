# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:modes\<\>\(\)
Defined in fragment [xieite:algorithms.modes](../../../src/algorithms/modes.cpp)

&nbsp;

## Description
Finds the modes (or antimodes) of a range of numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> Functor = std::ranges::greater>
requires(std::ranges::sized_range<Range> && xieite::concepts::Arithmetic<std::ranges::range_value_t<Range>>)
[[nodiscard]] constexpr std::vector<std::ranges::iterator_t<Range>> modes(Range& range, Functor&& comparator = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_common_reference_t<Range>, std::ranges::range_common_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::vector<int> data = { 1, 3, 2, 4, 5 };
    // 3 is greater than both 1 and 2
    // 5 is greater than 4 and is at the end of the array

    for (auto iterator : xieite::algorithms::modes(data)) {
        std::println("{}", *iterator);
    }
}
```
Output:
```
3
5
```
