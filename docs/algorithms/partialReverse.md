# xieite::algorithms::partialReverse
Defined in header `<xieite/algorithms/partialReverse.hpp>`

<br/>

Selects iterators and then reverses them in their same overall positions.

<br/><br/>

## Declarations
```cpp
template<std::forward_iterator Iterator>
constexpr void partialReverse(Iterator begin, const Iterator end, xieite::concepts::SelectorCallback<typename std::iterator_traits<Iterator>::value_type> auto&& selector) noexcept;
```

<br/><br/>

## Example
```cpp
#include <array> // std::array
#include <iostream> // std::cout
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
