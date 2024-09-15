# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:partialReverse\<\>\(\)
Defined in fragment [xieite:algorithms.partialReverse](../../../src/algorithms/partial_reverse.cpp)

&nbsp;

## Description
Selects iterators and then reverses them only between themselves.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::bidirectional_range Range, xieite::concepts::Invocable<bool(std::ranges::range_common_reference_t<Range>)> Functor>
requires(std::indirectly_swappable<std::ranges::iterator_t<Range>>)
constexpr void partialReverse(Range& range, Functor&& selector)
noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_common_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>);
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::array<int, 5> values { 1, 2, 3, 4, 5 };

    auto callback = [](int value) {
        return value <= 3;
    };

    xieite::algorithms::partialReverse(values, callback);

    for (int value : values) {
        std::print("{} ", value);
    }
    std::println();
}
```
Output:
```
3 2 1 4 5
```
