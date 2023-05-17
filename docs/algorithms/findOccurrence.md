# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::findOccurrence`
Defined in header [`<xieite/algorithms/findOccurrence.hpp>`](../../include/xieite/algorithms/findOccurrence.hpp)

<br/>

Finds the pointer to a specific occurrence of a value in an iterable. If the value is not found, returns the end pointer. Uses `std::equal_to` as the default comparator.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::forward_iterator ForwardIterator, xieite::concepts::Function<bool(std::iter_value_t<ForwardIterator>, std::iter_value_t<ForwardIterator>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr ForwardIterator findOccurrence(ForwardIterator begin, std::sentinel_for<ForwardIterator> auto end, const std::convertible_to<std::iter_value_t<ForwardIterator>> auto& value, std::size_t count, const Callback& comparator = Callback());
```
### Template parameters
- `ForwardIterator` - An iterator type, satisfying `std::forward_iterator`
- `Callback` - A callback type, satisfying `xieite::concepts::Function` which accepts two `ForwardIterator` value types and returns a `bool`. Set to `std::ranges::equal_to` by default
### Parameters
- `begin` - A `ForwardIterator` copy which points to the beginning of an iterable
- `end` - An `auto` copy, satisfying `std::sentinel_for` of `ForwardIterator`
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- The `ForwardIterator` pointing to the specified value occurrence, or to the end if it is not found.

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