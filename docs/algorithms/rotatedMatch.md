# xieite::algorithms::rotatedMatch
Defined in header `<xieite/algorithms/rotatedMatch.hpp>`

<br/>

Checks whether one iterable contains elements in the same relative order as in another iterable. If the end of the second iterable is encountered, the algorithm will "wrap" around and continue from its beginning.

<br/><br/>

## Declarations
```cpp
template<std::forward_iterator Iterator1, std::forward_iterator Iterator2, xieite::concepts::ComparatorCallback<typename std::iterator_traits<Iterator1>::value_type> Callback = std::equal_to<typename std::iterator_traits<Iterator1>::value_type>>
requires(std::same_as<typename std::iterator_traits<Iterator1>::value_type, typename std::iterator_traits<Iterator2>::value_type>)
[[nodiscard]]
constexpr bool rotatedMatch(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Iterator2 end2, Callback&& comparator = Callback()) noexcept;
```

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
