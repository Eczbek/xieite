# xieite::algorithms::rotatedMatch
Declared in `<xieite/algorithms/rotatedMatch.hpp>`

<br/>

Checks whether one iterable contains elements in the same relative order as in another iterable.

<br/><br/>

## Declarations
```cpp
template<std::forward_iterator I1, std::forward_iterator I2, xieite::concepts::Comparator<typename std::iterator_traits<I1>::value_type> F>
requires(std::same_as<typename std::iterator_traits<I1>::value_type, typename std::iterator_traits<I2>::value_type>)
[[nodiscard]]
constexpr bool rotatedMatch(const I1 begin1, const I1 end1, const I2 begin2, const I2 end2, F&& comparator) noexcept;
```
```cpp
template<std::forward_iterator I1, std::forward_iterator I2>
[[nodiscard]]
constexpr bool rotatedMatch(const I1 begin1, const I1 end1, const I2 begin2, const I2 end2) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
#include <vector> // std::vector
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
