# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:isRotated\<\>\(\)
Defined in header [<xieite/algorithms/is_rotated.hpp>](../../../include/xieite/algorithms/is_rotated.hpp)

&nbsp;

## Description
Checks whether one range contains elements in the same relative order as in another range.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::input_range Range1, std::ranges::input_range Range2, xieite::concepts::Functor<bool(std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>)> Functor = std::ranges::equal_to>
[[nodiscard]] constexpr bool isRotated(Range1&& range1, Range2&& range2, Functor&& comparator = Functor())
noexcept(std::is_nothrow_invocable_v<Functor, std::ranges::range_reference_t<Range1>, std::ranges::range_reference_t<Range2>>);
```

&nbsp;

## Example
```cpp
#include <print>
#include <vector>
#include "xieite/algorithms/is_rotated.hpp"

int main() {
    std::vector<int> foo { 1, 2, 3, 4, 5 };
    //                    |>  >  >  >  >|

    std::vector<int> bar { 4, 5, 1, 2, 3 };
    //                     >  >||>  >  >

    std::vector<int> baz { 3, 2, 1, 5, 4 };
    //                     <  <  <||<  <

    std::vector<int> qux { 5, 4, 3, 2, 1 };
    //                    |<  <  <  <  <|

    std::println("{}", xieite::algorithms::isRotated(foo, bar));
    std::println("{}", xieite::algorithms::isRotated(foo, baz));
    std::println("{}", xieite::algorithms::isRotated(baz, qux));
}
```
Output:
```
true
false
true
```
