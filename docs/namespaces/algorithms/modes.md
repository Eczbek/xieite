# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:modes\<\>\(\)
Defined in fragment [xieite:algorithms.modes](../../../src/algorithms/modes.cpp)

&nbsp;

## Description
Computes the modes (or antimodes) of a set of data.

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
    std::vector<int> data { 1, 3, 2, 4, 5 };

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
