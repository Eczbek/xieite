# xieite::algorithms::partialReverse
Defined in header `<xieite/algorithms/partialReverse.hpp>`

<br/>

Selects iterators and then reverses them in their same overall positions.

<br/><br/>

## Declaration
```cpp
template<std::forward_iterator I, std::invocable<typename std::iterator_traits<I>::value_type> C>
requires(std::convertible_to<std::invoke_result_t<C, typename std::iterator_traits<I>::value_type&&>, bool>)
constexpr void partialReverse(I begin, const I end, C&& selector) noexcept;
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
