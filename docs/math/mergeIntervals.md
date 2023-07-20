# [xieite](../xieite.md)::[math](../math.md)::mergeIntervals
Defined in header [<xieite/math/mergeIntervals.hpp>](../../include/xieite/math/mergeIntervals.hpp)

<br/>

Merges intervals if they overlap

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr std::vector<xieite::math::Interval<Number>> mergeIntervals(const xieite::concepts::RangeOf<xieite::math::Interval<Number>> auto& intervals) noexcept;
```
### Template parameters
- `Number` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `intervals` - A constant `auto` reference satisfying `xieite::concepts::RangeOf` of `xieite::math::Interval` of `Number`
### Return value
- A `std::vector` of `xieite::math::Interval`s of `Number`, the merged intervals

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Interval.hpp>
#include <xieite/math/mergeIntervals.hpp>

int main() {
	std::vector<xieite::math::Interval<int>> intervals {
		xieite::math::Interval<int>(1, 3),
		xieite::math::Interval<int>(2, 4),
		xieite::math::Interval<int>(5, 7)
	};

	for (const xieite::math::Interval<int> interval : xieite::math::mergeIntervals(intervals)) {
		std::cout << interval.start << ' ' << interval.end << '\n';
	}
}
```
Output:
```
1 4
5 7
```
