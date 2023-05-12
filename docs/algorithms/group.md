# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::group`
Defined in header [`<xieite/algorithms/group.hpp>`](../../include/xieite/algorithms/group.hpp)

<br/>

Groups elements of a vector into a `std::unordered_map`. The resulting map's keys depend on the return value of the callback.

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::forward_iterator Iterator, std::invocable<std::iter_value_t<Iterator>> Callback>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<Iterator>)>, std::vector<std::iter_value_t<Iterator>>> group(Iterator begin, std::sentinel_for<Iterator> auto end, const Callback& callback);
```
### Template parameters
- `Iterator` - The passed iterators' type, satisfying `std::forward_iterator`
- `Callback` - The callback type, satisfying `std::invocable` where it accepts `Iterator`'s value type
### Parameters
- `begin` - An `Iterator` copy, pointing the the beginning of an iterable
- `end` - An `auto` copy, satisfying `std::sentinel_for` of `Iterator`
- `callback` - A `Callback` constant reference
### Return value
- An `std::unordered_map`, of which the keys type depends on the return type of the callback, and the values type is a `std::vector` of `Iterator`'s value type

<br/><br/>

```cpp
template<std::forward_iterator Iterator, std::invocable<std::iter_value_t<Iterator>, std::size_t> Callback>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<Callback(std::iter_value_t<Iterator>, std::size_t)>, std::vector<std::iter_value_t<Iterator>>> group(Iterator begin, const std::sentinel_for<Iterator> auto end, const Callback& callback);
```
### Template parameters
- `Iterator` - The passed iterators' type, satisfying `std::forward_iterator`
- `Callback` - The callback type, satisfying `std::invocable` where it accepts `Iterator`'s value type and a `std::size_t`
### Parameters
- `begin` - An `Iterator` copy, pointing the the beginning of an iterable
- `end` - An `auto` copy, satisfying `std::sentinel_for` of `Iterator`
- `callback` - A `Callback` constant reference
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
