# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:findOccurrence\<\>\(\)
Defined in fragment [xieite:algorithms.findOccurrence](../../../src/algorithms/find_occurrence.cpp)

&nbsp;

## Description
Finds a specific occurrence of a value in a range and returns an iterator pointing to it, or the end if the value is not found.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
requires(std::ranges::sized_range<Range>)
[[nodiscard]] constexpr std::ranges::iterator_t<Range> findOccurrence(Range& range, std::size_t count, const std::ranges::range_reference_t<Range> value, Functor&& comparator = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    //               indices: 0  1  2  3  4  5  6
    std::vector<int> values { 1, 2, 1, 3, 1, 4, 1 };
    //           occurrences: 0     1     2     3

    auto result = xieite::algorithms::findOccurrence(values, 3, 1);

    std::println("{}", std::ranges::distance(values.begin(), result));
}
```
Output:
```
6
```
