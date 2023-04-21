# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::group`
Defined in header [`<xieite/algorithms/group.hpp>`](../../include/xieite/algorithms/group.hpp)

<br/>

Groups elements of a vector into a `std::unordered_map`. The resulting map's keys depend on the return value of the callback.

<br/><br/>

## Synopses

<br/>

```cpp
template<std::forward_iterator Iterator, std::invocable<std::iterator_traits<Iterator>::value_type> Callback>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<Callback(std::iterator_traits<Iterator>::value_type)>, std::vector<std::iterator_traits<Iterator>::value_type>> group(const Iterator begin, const Iterator end, Callback&& callback) noexcept;
```
### Template parameters
- `Iterator` - The passed iterators' type, satisfying `std::forward_iterator`
- `Callback` - The callback type, satisfying `std::invocable` where it accepts `Iterator`'s value type
### Parameters
- `begin` - An `Iterator` copy, pointing the the beginning of an iterable
- `end` - Also an `Iterator` copy, pointing to the end of the same iterable
- `callback` - A `Callback` right-value reference
### Return value
- `std::unordered_map<std::invoke_result_t<Callback(std::iterator_traits<Iterator>::value_type)>, std::vector<std::iterator_traits<Iterator>::value_type>>` - A `std::unordered_map`, of which the keys type depends on the return type of the callback, and the values type is a `std::vector` of `Iterator`'s value type

<br/>

```cpp
template<std::forward_iterator Iterator, std::invocable<std::iterator_traits<Iterator>::value_type, std::size_t> Callback>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<Callback(std::iterator_traits<Iterator>::value_type, std::size_t)>, std::vector<std::iterator_traits<Iterator>::value_type>> group(Iterator begin, const Iterator end, Callback&& callback) noexcept;
```
### Template parameters
- `Iterator` - The passed iterators' type, satisfying `std::forward_iterator`
- `Callback` - The callback type, satisfying `std::invocable` where it accepts `Iterator`'s value type and a `std::size_t`
### Parameters
- `begin` - An `Iterator` copy, pointing the the beginning of an iterable
- `end` - An `Iterator` copy, pointing to the end of the same iterable
- `callback` - A `Callback` right-value reference
### Return value
- A `std::unordered_map`, of which the keys' type depends on the return type of the callback, and the values' type is a `std::vector` of `Iterator`'s value type

<br/><br/>

## Example
```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <xieite/algorithms/group.hpp>

int main() {
	std::vector<int> values { 1, 2, 3, 4, 5 };

	auto callback = [](int value) -> bool {
		return value % 2;
	};

	std::unordered_map<bool, std::vector<int>> groups = xieite::algorithms::group(values, callback);

	std::cout << "true: ";
	for (int value : groups[true]) {
		std::cout << value << ' ';
	}
	std::cout << "\nfalse: ";
	for (int value : groups[false]) {
		std::cout << value << ' ';
	}
	std::cout << '\n';
}
```
Output:
```
true: 1 3 5
false: 2 4
```
