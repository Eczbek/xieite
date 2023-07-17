# [xieite](../xieite.md)::[algorithms](../algorithms.md)::sameRelativeOrder
Defined in header [<xieite/algorithms/sameRelativeOrder.hpp>](../../include/xieite/algorithms/sameRelativeOrder.hpp)

<br/>

Checks whether one range contains elements in the same relative order as in another range

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::ranges::range Range1, std::ranges::range Range2, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range1>, std::ranges::range_value_t<Range2>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr bool sameRelativeOrder(const Range1& range1, const Range2& range2, const Callback& comparator = Callback());
```
### Template parameters
- `Range1` - The first range type, satisfying `std::ranges::range`
- `Range2` - The second range type, also satisfying `std::ranges::range`
- `Callback` - A callback type, satisfying `xieite::concepts::Functable` which accepts `std::ranges::range_value_t` of `Range1`, and `std::ranges::range_value_t` of `Range2`, and returns a `bool`. Set to `std::ranges::equal_to` by default
### Parameters
- `range1` - A `Range1` constant reference
- `range2` - A `Range2` constant reference
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- A `bool`, whether or not the ranges have the same relative sequence of values

<br/><br/>

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

	std::cout
		<< std::boolalpha
		<< xieite::algorithms::sameRelativeOrder(std::begin(a), std::end(a), std::begin(b), std::end(b)) << '\n'
		<< xieite::algorithms::sameRelativeOrder(std::begin(a), std::end(a), std::begin(c), std::end(c)) << '\n'
		<< xieite::algorithms::sameRelativeOrder(std::rbegin(a), std::rend(a), std::begin(c), std::end(c)) << '\n';
}
```
Output:
```
true
false
true
```
