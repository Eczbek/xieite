# gcufl::algorithms::partialReverse
Declared in `<gcufl/algorithms/partialReverse.hpp>`
```cpp
template<std::forward_iterator I>
void partialReverse(I begin, const I end, const std::function<bool(const typename std::iterator_traits<I>::value_type)>& callback) noexcept;
```
Partially reverses an iterable's elements.
## Example
```cpp
#include <array>
#include <gcufl/algorithms/partialReverse.hpp>
#include <iostream>

int main() {
	std::array<int, 5> values { 1, 2, 3, 4, 5 };
	
	gcufl::algorithms::partialReverse(values.begin(), values.end(), [](const int value) -> bool {
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
