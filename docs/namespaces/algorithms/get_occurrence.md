# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:getOccurrence\<\>\(\)
Defined in fragment [xieite:algorithms.getOccurrence](../../../src/algorithms/get_occurrence.cpp)

&nbsp;

## Description
Finds a specific occurrence of a functor accepting an item of a range and returning `true`, and returns an iterator pointing to it, or the end if the occurrence is not found.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range>)> Functor>
requires(std::ranges::sized_range<Range>)
[[nodiscard]] constexpr std::ranges::iterator_t<Range> getOccurrence(Range& range, std::size_t count, Functor&& selector = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>);
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

    auto result = xieite::algorithms::occurrence(values, 3, [](int value) -> bool {
        return value == 1;
    });

    std::println("{}", std::ranges::distance(values.begin(), result));
}
```
Output:
```
6
```
