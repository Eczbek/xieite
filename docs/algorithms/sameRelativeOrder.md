# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::sameRelativeOrder`
Defined in header [`<xieite/algorithms/sameRelativeOrder.hpp>`](../../include/xieite/algorithms/sameRelativeOrder.hpp)

<br/>

Checks whether one iterable contains elements in the same relative order as in another iterable. If the end of the second iterable is encountered, the algorithm will "wrap" around and continue from its beginning.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::forward_iterator ForwardIterator1, std::forward_iterator ForwardIterator2, xieite::concepts::Functional<bool(std::iter_value_t<ForwardIterator1>, std::iter_value_t<ForwardIterator2>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr bool sameRelativeOrder(ForwardIterator1 begin1, std::sentinel_for<ForwardIterator1> auto end1, ForwardIterator2 begin2, std::sentinel_for<ForwardIterator2> auto end2, const Callback& comparator = Callback());
```
### Template parameters
- `ForwardIterator1` - An iterator type, satisfying `std::forward_iterator`
- `ForwardIterator2` - An iterator type, satisfying `std::forward_iterator`
- `Callback` - A callback type, satisfying `xieite::concepts::Functional` which accepts `ForwardIterator1`'s value type and `ForwardIterator2`'s value type, and returns a `bool`. Set to `std::ranges::equal_to` by default
### Parameters
- `begin1` - A `ForwardIterator1` copy which points to the beginning of an iterable
- `end1` - A `auto` copy, satisfying `std::iter_value_t` of `ForwardIterator1`
- `begin2` - A `ForwardIterator2` copy which points to the beginning of another iterable
- `end2` - A `auto` copy, satisfying `std::iter_value_t` of `ForwardIterator2`
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- A `bool`, whether or not the iterables have the same relative sequence of values

<br/><br/>

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/sameRelativeOrder.hpp>

int main() {
	std::vector<int> a { 1, 2, 3, 4, 5 };
	//                  |>  >  >  >  >|

	std::vector<int> b { 4, 5, 1, 2, 3 };
	//                   >  >||>  >  >

	std::vector<int> c { 3, 2, 1, 5, 4 };
	//                   <  <  <||<  <

	std::cout
		<< std::boolalpha
		<< xieite::algorithms::sameRelativeOrder(std::begin(a), std::end(a), std::begin(b), std::end(b))
		<< '\n'
		<< xieite::algorithms::sameRelativeOrder(std::begin(a), std::end(a), std::begin(c), std::end(c))
		<< '\n'
		<< xieite::algorithms::sameRelativeOrder(std::rbegin(a), std::rend(a), std::begin(c), std::end(c))
		<< '\n';
}
```
Output:
```
true
false
true
```

<br/><br/>

## See also
- [`xieite::concepts::Functional`](../../docs/concepts/Function.md)
