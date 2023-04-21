# `xieite::algorithms::rotatedMatch`
Defined in header [`<xieite/algorithms/rotatedMatch.hpp>`](../../include/xieite/algorithms/rotatedMatch.hpp)

<br/>

Checks whether one iterable contains elements in the same relative order as in another iterable. If the end of the second iterable is encountered, the algorithm will "wrap" around and continue from its beginning.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::forward_iterator Iterator1, std::forward_iterator Iterator2, xieite::concepts::CallbackComparator<typename std::iterator_traits<Iterator1>::value_type> Callback = std::equal_to<typename std::iterator_traits<Iterator1>::value_type>>
requires(std::same_as<typename std::iterator_traits<Iterator1>::value_type, typename std::iterator_traits<Iterator2>::value_type>)
[[nodiscard]]
constexpr bool rotatedMatch(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Iterator2 end2, Callback&& comparator = Callback()) noexcept;
```
### Template parameters
- `Iterator1` - An iterator type, satisfying `std::forward_iterator`
- `Iterator2` - An iterator type, satisfying `std::forward_iterator`
- `Callback` - A callback type, satisfying `xieite::concepts::CallbackComparator` of `Iterator1`'s value type, set to `std::equal_to` of `Iterator1`'s value type by default
### Requirements
- `Iterator1`'s value type must be the same as `Iterator2`'s value type
### Parameters
- `begin1` - An `Iterator1` copy which points to the beginning of an iterable
- `end1` - An `Iterator1` copy which points to the end of the same iterable
- `begin2` - An `Iterator2` copy which points to the beginning of another iterable
- `end2` - An `Iterator2` copy which points to the end of the second iterable
- `comparator` - A `Callback` right-value reference, default-constructed by default
### Return value
- A `bool`, whether or not the iterables have the same relative sequence of values

<br/><br/>

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/rotatedMatch.hpp>

int main() {
	std::vector<int> a { 1, 2, 3, 4, 5 };
	//                  |>  >  >  >  >|

	std::vector<int> b { 4, 5, 1, 2, 3 };
	//                   >  >||>  >  >

	std::vector<int> c { 3, 2, 1, 5, 4 };
	//                   <  <  <||<  <

	std::cout << std::boolalpha
		<< xieite::algorithms::rotatedMatch(std::begin(a), std::end(a), std::begin(b), std::end(b)) << '\n'
		<< xieite::algorithms::rotatedMatch(std::begin(a), std::end(a), std::begin(c), std::end(c)) << '\n'
		<< xieite::algorithms::rotatedMatch(std::rbegin(a), std::rend(a), std::begin(c), std::end(c)) << '\n';
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
- [`xieite::concepts::CallbackComparator`](../../docs/concepts/CallbackComparator.md)
