# [xieite](../../xieite.md)\:\:[ranges](../../ranges.md)\:\:makeArray
Defined in header [<xieite/ranges/make_array.hpp>](../../../include/xieite/ranges/make_array.hpp)

&nbsp;

## Description
Attempts to create `std::array`s from other ranges.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Value, std::size_t size, std::ranges::range Range>
requires(std::convertible_to<std::ranges::range_value_t<Range>, Value>)
[[nodiscard]] constexpr std::array<Value, size> makeArray(const Range& range)
noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_value_t<Range>, Value>);
```
#### 2)
```cpp
template<typename... Arguments, typename Value = std::common_type_t<Arguments...>, std::size_t size = sizeof...(Values)>
requires(sizeof...(Arguments) <= size)
[[nodiscard]] constexpr std::array<Value, size> makeArray(const Arguments&... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/ranges/make_array.hpp>

int main() {
    std::vector<int> source { 1, 2, 3, 4, 5 };

    auto result = xieite::ranges::makeArray<int, 5>(source);

    for (int item : result) {
        std::cout << item << '\n';
    }
}
```
Output:
```
14
```
