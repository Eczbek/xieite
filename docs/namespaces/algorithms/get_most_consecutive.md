# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:getMostConsecutive\<\>\(\)
Defined in fragment [xieite:algorithms.getMostConsecutive](../../../src/algorithms/get_most_consecutive.cpp)

&nbsp;

## Description
Finds the subrange of greatest length containing the maximum number of consecutive invocations of a functor returning `true`. If no functors return `true`, returns a subrange where both iterators are set to the range's end.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range>)> Functor>
requires(std::ranges::sized_range<Range>)
[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>> getMostConsecutive(Range& range, Functor&& selector = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>);
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

    auto result = xieite::algorithms::getMostConsecutive(values, [](int value) -> bool {
        return value == 1;
    });

    std::println("{} - {}", std::ranges::distance(values.begin(), result.begin()), std::ranges::distance(values.begin(), result.end()));
}
```
Output:
```
2 - 5
```
