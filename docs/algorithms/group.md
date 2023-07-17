# [xieite](../xieite.md)::[algorithms](../algorithms.md)::group
Defined in header [<xieite/algorithms/group.hpp>](../../include/xieite/algorithms/group.hpp)

<br/>

Groups elements of a `std::vector` into a `std::unordered_map`. The resulting map's keys depend on the return value of the callback provided

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>> Callback>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<Callback(std::ranges::range_value_t<Range>)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Callback& callback);
```
### Template parameters
- `Range` - The range type, satisfying `std::ranges::range`
- `Callback` - The callback type, satisfying `std::invocable` where it accepts a `std::ranges::range_value_t` of `Range`
### Parameters
- `range` - A `Range` constant reference
- `callback` - A `Callback` constant reference
### Return value
- A `std::unordered_map`, of which the keys type depends on the return type of `callback`, and the values type is a `std::vector` of `std::ranges::range_value_t` of `Range`

<br/><br/>

```cpp
template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>, std::size_t> Callback>
[[nodiscard]]
std::unordered_map<std::invoke_result_t<Callback(std::ranges::range_value_t<Range>, std::size_t)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Callback& callback);
```
### Template parameters
- `Range` - The range type, satisfying `std::ranges::range`
- `Callback` - The callback type, satisfying `std::invocable` where it accepts `std::ranges::range_value_t` of `Range`, and a `std::size_t`
### Parameters
- `range` - A `Range` constant reference
- `callback` - A `Callback` constant reference
### Return value
- A `std::unordered_map`, of which the keys' type depends on the return type of `callback`, and the values' type is a `std::vector` of `std::ranges::range_value_t` of `Range`

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
