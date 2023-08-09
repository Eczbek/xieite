# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:sameRelativeOrder
Defined in header [<xieite/algorithms/sameRelativeOrder.hpp>](../../include/xieite/algorithms/sameRelativeOrder.hpp)

&nbsp;

## Description
Checks whether one range contains elements in the same relative order as in another range

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range1, std::ranges::range Range2, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range1>, std::ranges::range_value_t<Range2>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr bool sameRelativeOrder(const Range1& range1, const Range2& range2, const Callback& comparator = Callback());
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/sameRelativeOrder.hpp>

int main() {
    std::vector<int> a { 1, 2, 3, 4, 5 };
    //                  |>  >  >  >  >|

    std::vector<int> b { 4, 5, 1, 2, 3 };
    //                   >  >||>  >  >

    std::vector<int> c { 3, 2, 1, 5, 4 };
    //                   <  <  <||<  <

    std::vector<int> d { 5, 4, 3, 2, 1 };
    //                  |<  <  <  <  <|

    std::cout
        << std::boolalpha
        << xieite::algorithms::sameRelativeOrder(a, b) << '\n'
        << xieite::algorithms::sameRelativeOrder(a, c) << '\n'
        << xieite::algorithms::sameRelativeOrder(c, d) << '\n';
}
```
Output:
```
true
false
true
```
