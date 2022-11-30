# xieite::algorithms::partialReverse
Declared in `<xieite/algorithms/partialReverse.hpp>`

<br/>

Partially reverses an iterable's elements.

<br/><br/>

## Declaration
```cpp
template<std::forward_iterator I, xieite::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
constexpr void partialReverse(I begin, const I end, const F& selector) noexcept;
```

<br/><br/>

## Example
```cpp
#include <array>
#include <iostream>
#include <xieite/algorithms/partialReverse.hpp>

int main() {
	std::array<int, 5> values { 1, 2, 3, 4, 5 };
	
	xieite::algorithms::partialReverse(values.begin(), values.end(), [](const int value) -> bool {
		return value <= 3;
	});

	for (const int value : values)
		std::cout << value << ' ';
	std::cout << '\n';
}
```
Output:
```
3 2 1 4 5 
```
