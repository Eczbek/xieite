# [xieite](../xieite.md)::[algorithms](../algorithms.md)::partialReverse
Defined in header [<xieite/algorithms/partialReverse.hpp>](../../include/xieite/algorithms/partialReverse.hpp)

<br/>

Selects iterators and then reverses them in their same overall positions

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>)> Functable>
constexpr void partialReverse(const Range& range, const Functable& selector);
```
### Template parameters
- `Range` - The range type satisfying `std::ranges::range`
- `Functable` - A functor type satisfying `xieite::concepts::Functable` which accepts a `std::ranges::range_value_t` of `Range`, and returns a `bool`
### Parameters
- `range` - A constant `Range` reference
- `selector` - A constant `Functable` reference

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
	
	xieite::algorithms::partialReverse(values, callback);

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
