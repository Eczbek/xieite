# xieite::algorithms::rotatedMatch
Declared in `<xieite/algorithms/rotatedMatch.hpp>`

<br/>

Checks whether one iterable contains elements in the same relative order as in another iterable.

<br/><br/>

## Declarations
```cpp
template<std::forward_iterator I, std::forward_iterator J, xieite::concepts::Comparator<typename std::iterator_traits<I>::value_type> C>
requires(std::same_as<typename std::iterator_traits<I>::value_type, typename std::iterator_traits<J>::value_type>)
[[nodiscard]]
constexpr bool rotatedMatch(const I begin1, const I end1, const J begin2, const J end2, C&& comparator) noexcept;
```
```cpp
template<std::forward_iterator I, std::forward_iterator J>
[[nodiscard]]
constexpr bool rotatedMatch(const I begin1, const I end1, const J begin2, const J end2) noexcept;
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
