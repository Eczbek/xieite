# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:sameRelativeOrder
Defined in header [<xieite/algorithms/same_relative_order.hpp>](../../../include/xieite/algorithms/same_relative_order.hpp)

&nbsp;

## Description
Checks whether one range contains elements in the same relative order as in another range.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range1, std::ranges::range Range2, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>)> Functor = std::ranges::equal_to>
[[nodiscard]] constexpr bool isSameRelativeOrder(Range1&& range1, Range2&& range2, Functor&& comparator = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/is_same_relative_order.hpp>

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
        << xieite::algorithms::isSameRelativeOrder(a, b) << '\n'
        << xieite::algorithms::isSameRelativeOrder(a, c) << '\n'
        << xieite::algorithms::isSameRelativeOrder(c, d) << '\n';
}
```
Output:
```
true
false
true
```
