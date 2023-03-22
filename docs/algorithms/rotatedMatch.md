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
constexpr bool rotatedMatch(const Iterator1 begin1, const Iterator1 end1, const Iterator2 begin2, const Iterator2 end2, Callback&& comparator = Callback()) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/algorithms/rotatedMatch.hpp>

int main() {
	const std::vector<int> a { 1, 2, 3, 4, 5 };
	//                        |>  >  >  >  >|
	const std::vector<int> b { 4, 5, 1, 2, 3 };
	//                         >  >||>  >  >
	const std::vector<int> c { 3, 2, 1, 5, 4 };
	//                         <  <  <||<  <

	std::cout << std::boolalpha
		<< xieite::algorithms::rotatedMatch(a.begin(), a.end(), b.begin(), b.end()) << '\n'
		<< xieite::algorithms::rotatedMatch(a.begin(), a.end(), c.begin(), c.end()) << '\n'
		<< xieite::algorithms::rotatedMatch(a.rbegin(), a.rend(), c.begin(), c.end()) << '\n';
}
```
Output:
```
true
false
true
```
