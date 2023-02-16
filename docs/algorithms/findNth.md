# xieite::algorithms::findNth
Declared in `<xieite/algorithms/findNth.hpp>`

<br/>

Finds the Nth occurence of a value.

<br/><br/>

## Declarations
```cpp
template<std::forward_iterator I, xieite::concepts::Comparator<typename std::iterator_traits<I>::value_type> C>
[[nodiscard]]
constexpr I findNth(I begin, const I end, typename std::iterator_traits<I>::value_type&& value, std::size_t count, C&& comparator) noexcept;
```
```cpp
template<std::forward_iterator I>
[[nodiscard]]
constexpr I findNth(const I begin, const I end, typename std::iterator_traits<I>::value_type&& value, const std::size_t count) noexcept;
```

<br/><br/>

## Example
```cpp
#include <array> // std::array
#include <iostream> // std::cout
#include <iterator> // std::distance
#include <xieite/algorithms/findNth.hpp>

int main() {
	std::array<int, 7> values { 1, 2, 1, 3, 1, 4, 1 };
	std::cout << std::distance(values.begin(), xieite::algorithms::findNth(values.begin(), values.end(), 1, 3)) << '\n';
}
```
Output:
```
4
```
