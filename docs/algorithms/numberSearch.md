# [xieite](../../README.md)::[algorithms](../algorithms.md)::numberSearch
Defined in header [<xieite/algorithms/numberSearch.hpp>](../../include/xieite/algorithms/numberSearch.hpp)

<br/>

Using a variant of the binary search algorithm, finds the lowest value which, if passed to the callback, will return `true`. If not given minimum and maximum search limits, starting from 1, will exponentially decrease or increase a limit until it contains the possible range. The callback **must** be logically equaivalent to (x >= y), where x is the callback parameter and y is the desired limit

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number numberSearch(const xieite::concepts::Functional<bool(Number)> auto& selector, Number minimum, Number maximum);
```
### Template parameters
- `Number` - An integer or floating point type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `selector` - An `auto` constant reference, satisfying `xieite::concepts::Functional` which accepts `Iterator`'s value type and returns a `bool`
- `minimum` - A `Number` copy, determining the minimum search limit for the algorithm
- `maxumum` - A `Number` copy, determining the maxumum search limit for the algorithm
### Return value
- A `Number`, the lowest value allowed by the callback

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number numberSearch(const xieite::concepts::Functional<bool(Number)> auto& selector);
```
### Template parameters
- `Number` - An integer or floating point type, satisfying `xieite::concepts::Arithmetic`
- `Callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` which accepts `Iterator`'s value type and returns a `bool`
### Parameters
- `selector` - A `Callback` constant reference
### Return value
- `Number` - The lowest value allowed by the callback

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/numberSearch.hpp>

bool checkCollision(double x) {
	return x < 10;
}

int main() {
	auto callback = [](double x) -> bool {
		return !checkCollision(x);
	};

	std::cout << xieite::algorithms::numberSearch(callback, 5.0, 15.0) << '\n';
}
```
Output:
```
10
```
