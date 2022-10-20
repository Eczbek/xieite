# gcufl::algorithms::findNth
Declared in `<gcufl/algorithms/findNth.hpp>`
```cpp
template<std::forward_iterator I, gcufl::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
[[nodiscard]]
constexpr I findNth(I begin, const I end, std::size_t count, const typename std::iterator_traits<I>::value_type& value, const F& comparator) noexcept;

template<std::forward_iterator I>
[[nodiscard]]
constexpr I findNth(const I begin, const I end, const std::size_t count, const typename std::iterator_traits<I>::value_type& value) noexcept;
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
