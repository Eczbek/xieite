# [xieite](../xieite.md)::[algorithms](../algorithms.md)::numberSearch
Defined in header [<xieite/algorithms/numberSearch.hpp>](../../include/xieite/algorithms/numberSearch.hpp)

<br/>

Using a variant of the binary search algorithm, finds the lowest value which, if passed to the callback, will return `true`. If not given minimum and maximum search limits, starting from 1, will exponentially decrease or increase a limit until it contains the possible range. The callback **must** be logically equaivalent to (x >= y), where x is the callback parameter and y is the desired limit

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functable<bool(Arithmetic)> Functable>
[[nodiscard]]
constexpr Arithmetic numberSearch(const Functable& selector, Arithmetic minimum, Arithmetic maximum);
```
### Template parameters
- `Arithmetic` - An integer or floating point type satisfying `xieite::concepts::Arithmetic`
- `Functable` - A functor type satisfying `xieite::concepts::Functable` which accepts a `Arithmetic` and returns a `bool`
### Parameters
- `selector` - A constant `Functable` reference
- `minimum` - An `Arithmetic`, determining the minimum search limit for the algorithm
- `maxumum` - An `Arithmetic`, determining the maxumum search limit for the algorithm
### Return value
- An `Arithmetic`, the lowest value allowed by the callback

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functable<bool(Arithmetic)> Functable>
[[nodiscard]]
constexpr Arithmetic numberSearch(const Functable& selector);
```
### Template parameters
- `Arithmetic` - An integer or floating point type satisfying `xieite::concepts::Arithmetic`
- `Functable` - A functor type satisfying `xieite::concepts::Functable` which accepts a `Arithmetic` and returns a `bool`
### Parameters
- `selector` - A `Functor` constant reference
### Return value
- An `Arithmetic` - The lowest value allowed by the callback

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
