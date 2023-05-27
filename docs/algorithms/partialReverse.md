# [xieite](../../README.md)::[algorithms](../algorithms.md)::partialReverse
Defined in header [<xieite/algorithms/partialReverse.hpp>](../../include/xieite/algorithms/partialReverse.hpp)

<br/>

Selects iterators and then reverses them in their same overall positions

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::ranges::range Range>
constexpr void partialReverse(const Range& range, const xieite::concepts::Functional<bool(std::ranges::range_value_t<Range>)> auto& selector);
```
### Template parameters
- `Range` - The range type, satisfying `std::ranges::range`
### Parameters
- `range` - A `Range` constant reference
- `selector` - An `auto` constant reference, satisfying `xieite::concepts::Functional` which accepts `std::ranges::range_value_t` of `Range`, and returns a `bool`

<br/><br/>

## Example
```cpp
#include <array>
#include <iostream>
#include <xieite/algorithms/partialReverse.hpp>

int main() {
	std::array<int, 5> values { 1, 2, 3, 4, 5 };

	auto callback = [](int value) -> bool {
		return value <= 3;
	};
	
	xieite::algorithms::partialReverse(std::begin(values), std::end(values), callback);

	for (int value : values) {
		std::cout << value << ' ';
	}
	std::cout << '\n';
}
```
Output:
```
3 2 1 4 5 
```
