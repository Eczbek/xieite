# gcufl::algorithms::rotatedMatch
Declared in `<gcufl/algorithms/rotatedMatch.hpp>`
```cpp
template <std::forward_iterator I1, std::forward_iterator I2>
bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2) noexcept;

template <std::forward_iterator I1, std::forward_iterator I2>
bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2, const std::function<bool(const typename std::iterator_traits<I1>::value_type&, const typename std::iterator_traits<I2>::value_type&)>& callback) noexcept;
```
Checks whether one iterable contains elements in the same relative order as in another iterable.
<br/>
1. Compares elements with `*a != *b`.
2. Compares elements with `!callback(*a, *b)`.
## Example
```cpp
#include <gcufl/algorithms/rotatedMatch.hpp>
#include <iostream>
#include <vector>

int main() {
	const std::vector<int> a { 1, 2, 3, 4, 5 };
	//					      |>  >  >  >  >|
	const std::vector<int> b { 4, 5, 1, 2, 3 };
	//					       >  >||>  >  >
	const std::vector<int> c { 3, 2, 1, 5, 4 };
	//		     			   <  <  <||<  <

	std::cout << std::boolalpha
		<< gcufl::algorithms::rotatedMatch(a.begin(), a.end(), b.begin(), b.end()) << '\n'
		<< gcufl::algorithms::rotatedMatch(a.begin(), a.end(), c.begin(), c.end()) << '\n'
		<< gcufl::algorithms::rotatedMatch(a.rbegin(), a.rend(), c.begin(), c.end()) << '\n';
}
```
Output:
```
true
false
true
```
