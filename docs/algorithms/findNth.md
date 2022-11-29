# xieite::algorithms::findNth
Declared in `<xieite/algorithms/findNth.hpp>`

```cpp
template<std::forward_iterator I, xieite::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
[[nodiscard]]
constexpr I findNth(I begin, const I end, const typename std::iterator_traits<I>::value_type& value, typename std::iterator_traits<I>::difference_type count, const F& comparator) noexcept;

template<std::forward_iterator I>
[[nodiscard]]
constexpr I findNth(const I begin, const I end, const typename std::iterator_traits<I>::value_type& value, const typename std::iterator_traits<I>::difference_type count) noexcept;
```

Finds the Nth occurence of a value.

## Example
```cpp
#include <array>
#include <iostream>
#include <iterator>
#include <xieite/algorithms/findNth.hpp>

int main() {
	std::array<int, 7> values { 1, 2, 1, 3, 1, 4, 1 };
	std::cout << std::distance(values.begin(), xieite::algorithms::findNth(values.begin(), values.end(), 2, 1)) << '\n';
}
```
Output:
```
4
```
