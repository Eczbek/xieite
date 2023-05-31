# [xieite](../../README.md)::[algorithms](../algorithms.md)::findOccurrence
Defined in header [<xieite/algorithms/findOccurrence.hpp>](../../include/xieite/algorithms/findOccurrence.hpp)

<br/>

Finds the pointer to a specific occurrence of a value in an range. If the value is not found, returns the end pointer

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr std::ranges::const_iterator_t<const Range&> findOccurrence(const Range& range, std::ranges::range_const_reference_t<Range> value, std::size_t count, const Callback& comparator = Callback());
```
### Template parameters
- `Range` - A range type, satisfying `std::ranges::range`
- `Callback` - A callback type, satisfying `xieite::concepts::Functable` which accepts two of `std::ranges::range_value_t` of `Range`, and returns a `bool`. Set to `std::ranges::equal_to` by default
### Parameters
- `range` - A `Range` constant reference
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- A `std::ranges::const_iterator_t` of a constant reference to `Range`, pointing to the specified value occurrence or to the end if it is not found

<br/><br/>

## Example
```cpp
#include <iostream>
#include <iterator>
#include <vector>
#include <xieite/algorithms/findOccurrence.hpp>

int main() {
	std::vector<int> values { 1, 2, 1, 3, 1, 4, 1 };

	std::vector<int>::iterator result = xieite::algorithms::findOccurrence(std::begin(values), std::end(values), 1, 3);
	
	std::cout << std::distance(std::begin(values), result) << '\n';
}
```
Output:
```
4
```
