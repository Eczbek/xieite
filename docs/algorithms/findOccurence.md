# xieite::algorithms::findOccurence
Defined in header `<xieite/algorithms/findOccurence.hpp>`

<br/>

Finds the pointer to a specific occurence of a value in an iterable. If the value is not found, returns the end pointer. Uses `std::equal_to` as the default comparator.

<br/><br/>

## Declarations
```cpp
template<std::forward_iterator I, xieite::concepts::Comparator<typename std::iterator_traits<I>::value_type> C = std::equal_to<typename std::iterator_traits<I>::value_type>>
[[nodiscard]]
constexpr I findOccurence(I begin, const I end, typename std::iterator_traits<I>::value_type&& value, std::size_t count, C&& comparator = C()) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <iterator> // std::distance
#include <vector> // std::vector
#include <xieite/algorithms/findOccurence.hpp>

int main() {
	std::vector<int> values { 1, 2, 1, 3, 1, 4, 1 };
	std::cout << std::distance(values.begin(), xieite::algorithms::findOccurence(values.begin(), values.end(), 1, 3)) << '\n';
}
```
Output:
```
4
```
