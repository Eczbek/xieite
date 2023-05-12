# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::partialReverse`
Defined in header [`<xieite/algorithms/partialReverse.hpp>`](../../include/xieite/algorithms/partialReverse.hpp)

<br/>

Selects iterators and then reverses them in their same overall positions.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<std::forward_iterator Iterator>
constexpr void partialReverse(Iterator begin, std::sentinel_for<Iterator> auto end, const xieite::concepts::Function<bool(std::iter_value_t<Iterator>)> auto& selector);
```
### Template parameters
- `Iterator` - An iterator type, satisfying `std::forward_iterator`
### Parameters
- `begin` - An `Iterator` copy which points to the beginning of an iterable
- `end` - An `auto` copy, satisfying `std::sentinel_for` of `Iterator`
- `selector` - An `auto` constant reference, satisfying `xieite::concepts::Function` which accepts `Iterator`'s value type and returns a `bool`

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

<br/><br/>

## See also
- [`xieite::concepts::Function`](../../docs/concepts/Function.md)
