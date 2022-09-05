# gcufl::algorithms::rotatedMatch
```cpp
template <std::forward_iterator I1, std::forward_iterator I2>
bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2) noexcept;

template <std::forward_iterator I1, std::forward_iterator I2, std::invocable<const typename std::iterator_traits<I1>::value_type&, const typename std::iterator_traits<I2>::value_type&> C>
bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2, const C& compare) noexcept;
```
Checks whether two iterables contain the same values in the same relative order.
## Example
```cpp
#include <array>
#include <gcufl/algorithms.hpp>
#include <iostream>

int main() {
	std::array<int, 5> a { 1, 2, 3, 4, 5 };
	std::array<int, 5> b { 3, 4, 5, 1, 2 };
	std::array<int, 5> c { 2, 1, 5, 4, 3 };

	std::cout
		<< std::boolalpha
		<< gcufl::algorithms::rotatedMatch(a.begin(), a.end(), b.begin(), b.end())
		<< '\n'
		<< gcufl::algorithms::rotatedMatch(a.begin(), a.end(), c.begin(), c.end())
		<< '\n'
		<< gcufl::algorithms::rotatedMatch(a.begin(), a.end(), c.rbegin(), c.rend())
		<< '\n';
}
```
Output:
```
true
false
true
```
