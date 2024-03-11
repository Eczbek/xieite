# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:group\(\)
Defined in header [<xieite/algorithms/group.hpp>](../../../include/xieite/algorithms/group.hpp)

&nbsp;

## Description
Groups elements of a range into a `std::unordered_map` of `std::vector`s of iterators, of which the keys' type depends on the return type of the callback provided.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range, std::invocable<std::ranges::range_reference_t<Range>> Functor>
[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor, std::ranges::range_reference_t<Range>>, std::vector<std::ranges::const_iterator_t<Range>>> group(Range&& range, Functor&& callback)
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>>);
```
#### 2)
```cpp
template<std::ranges::range Range, std::invocable<std::ranges::range_reference_t<Range>, std::size_t> Functor>
[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor, std::ranges::range_reference_t<Range>, std::size_t>, std::vector<std::ranges::const_iterator_t<Range>>> group(Range&& range, Functor&& callback)
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::size_t>);
```

&nbsp;

## Example
```cpp
#include <print>
#include <unordered_map>
#include <vector>
#include "xieite/algorithms/group.hpp"

int main() {
    std::vector<int> values { 1, 2, 3, 4, 5 };

    auto callback = [](int value) {
        return value % 2;
    };

    auto groups = xieite::algorithms::group(values, callback);

    std::print("true: ");
    for (auto iterator : groups[true]) {
        std::print("{} ", *iterator);
    }
    std::print("\nfalse: ");
    for (auto iterator : groups[false]) {
        std::print("{} ", *iterator);
    }
    std::println("");
}
```
Output:
```
true: 1 3 5
false: 2 4
```
