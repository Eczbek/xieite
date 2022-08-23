# gcufl::alg::rotatedMatch
```cpp
template <std::input_iterator I1, std::input_iterator I2>
bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2) noexcept;

template <std::input_iterator I1, std::input_iterator I2, typename C>
bool rotatedMatch(I1 begin1, const I1 end1, const I2 begin2, const I2 end2, const C& compare) noexcept;
```
Checks whether two iterables contain the same values in the same relative order.
## Example
```cpp
#include <iostream>
#include <array>
#include <gcufl/alg>

int main() {
	std::array<int, 5> a { 1, 2, 3, 4, 5 };
	std::array<int, 5> b { 3, 4, 5, 1, 2 };
	std::array<int, 5> c { 2, 1, 5, 4, 3 };

	std::cout
		<< std::boolalpha
		<< gcufl::alg::rotatedMatch(a.begin(), a.end(), b.begin(), b.end())
		<< '\n'
		<< gcufl::alg::rotatedMatch(a.begin(), a.end(), c.begin(), c.end())
		<< '\n'
		<< gcufl::alg::rotatedMatch(a.begin(), a.end(), c.rbegin(), c.rend())
		<< '\n';
}
```
Output:
```
true
false
true
```
