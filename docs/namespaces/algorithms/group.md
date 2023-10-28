# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:group
Defined in header [<xieite/algorithms/group.hpp>](../../../include/xieite/algorithms/group.hpp)

&nbsp;

## Description
Groups elements of a `std::vector` into a `std::unordered_map`, of which the keys' type depends on the return type of the callback provided.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>> Functor>
[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor(std::ranges::range_value_t<Range>)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Functor& callback)
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_value_t<Range>>);
```
#### 2)
```cpp
template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>, std::size_t> Functor>
[[nodiscard]] inline std::unordered_map<std::invoke_result_t<Functor(std::ranges::range_value_t<Range>, std::size_t)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Functor& callback)
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_value_t<Range>, std::size_t>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <xieite/algorithms/group.hpp>

int main() {
    std::vector<int> values { 1, 2, 3, 4, 5 };

    auto callback = [](int value) {
        return value % 2;
    };

    std::unordered_map<bool, std::vector<int>> groups = xieite::algorithms::group(values, callback);

    std::cout << "true: ";
    for (int value : groups[true]) {
        std::cout << value << ' ';
    }
    std::cout << "\nfalse: ";
    for (int value : groups[false]) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
```
Output:
```
true: 1 3 5
false: 2 4
```
