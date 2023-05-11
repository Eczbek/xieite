# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::findOccurrence`
Defined in header [`<xieite/algorithms/findOccurrence.hpp>`](../../include/xieite/algorithms/findOccurrence.hpp)

<br/>

Finds the pointer to a specific occurrence of a value in an iterable. If the value is not found, returns the end pointer. Uses `std::equal_to` as the default comparator.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<std::forward_iterator Iterator, xieite::concepts::Function<bool(typename std::iterator_traits<Iterator>::value_type, typename std::iterator_traits<Iterator>::value_type)> Callback = std::equal_to<typename std::iterator_traits<Iterator>::value_type>>
[[nodiscard]]
constexpr Iterator findOccurrence(Iterator begin, const Iterator end, const typename std::iterator_traits<Iterator>::value_type& value, std::size_t count, const Callback& comparator = Callback());
```
### Template parameters
- `Iterator` - An iterator type, satisfying `std::forward_iterator`
- `Callback` - A callback type, satisfying `xieite::concepts::Function` which accepts two `Iterator` value types and returns a `bool`. Set to `std::equal_to` of `Iterator`'s value type by default
### Parameters
- `begin` - An `Iterator` copy which points to the beginning of an iterable
- `end` - An `Iterator` copy which points to the end of the same iterable
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- The `Iterator` pointing to the specified value occurrence, or to the end if it is not found.

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

<br/><br/>

## See also
- [`xieite::concepts::Function`](../../docs/concepts/Function.md)