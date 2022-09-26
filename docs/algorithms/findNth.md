# gcufl::algorithms::findNth
Declared in `<gcufl/algorithms/findNth.hpp>`
```cpp
template<std::forward_iterator I>
constexpr I findNth(I begin, const I end, std::size_t count, const typename std::iterator_traits<I>::value_type& value, const std::function<bool(const typename std::iterator_traits<I>::value_type, const typename std::iterator_traits<I>::value_type)>& comparator = std::equal_to<const typename std::iterator_traits<I>::value_type>()) noexcept;
```
Finds the Nth occurence of a value, starting at 0.
## Example
```cpp
#include <array>
#include <gcufl/algorithms/findNth.hpp>
#include <iostream>
#include <iterator>

int main() {
	std::array<int, 7> values { 1, 2, 1, 3, 1, 4, 1 };
	std::cout << std::distance(values.begin(), gcufl::algorithms::findNth(values.begin(), values.end(), 2, 1)) << '\n';
}
```
Output:
```
4
```
