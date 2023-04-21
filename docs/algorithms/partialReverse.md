# `xieite::algorithms::partialReverse`
Defined in header [`<xieite/algorithms/partialReverse.hpp>`](../../include/xieite/algorithms/partialReverse.hpp)

<br/>

Selects iterators and then reverses them in their same overall positions.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::forward_iterator Iterator>
constexpr void partialReverse(Iterator begin, Iterator end, xieite::concepts::CallbackSelector<typename std::iterator_traits<Iterator>::value_type> auto&& selector) noexcept;
```
### Template parameters
- `Iterator` - An iterator type, satisfying `std::forward_iterator`
### Parameters
- `begin` - An `Iterator` copy which points to the beginning of an iterable
- `end` - An `Iterator` copy which points to the end of the same iterable
- `selector` - An `auto` right-value reference, satisfying `xieite::concepts::CallbackSelector` of `Iterator`'s value type

<br/><br/>

## Example
```cpp
#include <array>
#include <iostream>
#include <xieite/algorithms/partialReverse.hpp>

int main() {
	std::array<int, 5> values { 1, 2, 3, 4, 5 };
	
	xieite::algorithms::partialReverse(std::begin(values), std::end(values), [](int value) -> bool {
		return value <= 3;
	});

	for (int value : values)
		std::cout << value << ' ';
	std::cout << '\n';
}
```
Output:
```
3 2 1 4 5 
```

<br/><br/>

## See also
- [`xieite::concepts::CallbackSelector`](../../docs/concepts/CallbackSelector.md)
