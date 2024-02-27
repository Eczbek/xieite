# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:RangeOf
Defined in header [<xieite/concepts/range_of.hpp>](../../../include/xieite/concepts/range_of.hpp)

&nbsp;

## Description
Specifies that a type satisfies `std::ranges::range` and contains values of a specified type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Range, typename Value>
concept RangeOf = std::ranges::range<Range> && (std::same_as<std::ranges::range_reference_t<Range>, Value> || std::convertible_to<std::ranges::range_reference_t<Range>, Value>);
```

&nbsp;

## Example
```cpp
#include <array>
#include <print>
#include <vector>
#include "xieite/concepts/range_of.hpp"

template<xieite::concepts::RangeOf<int>>
void test() {
    std::println("yep");
}

template<typename>
void test() {
    std::println("nope");
}

int main() {
    test<std::array<int, 5>>();
    test<std::vector<double>>();
    test<unsigned short int>();
}
```
Output:
```
yep
yep
nope
```
