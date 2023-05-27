# [xieite](../../README.md)::[algorithms](../algorithms.md)::isPalindrome
Defined in header [<xieite/algorithms/isPalindrome.hpp>](../../include/xieite/algorithms/isPalindrome.hpp)

<br/>

Checks if a range is the same backwards as it is forwards

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::ranges::range Range, xieite::concepts::Functional<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr bool isPalindrome(const Range& range, const Callback& comparator = Callback());
```
### Template parameters
- `Range` - The range type, satisfying `std::ranges::range`
- `Callback` - A callback type, satisfying `xieite::concepts::Functional` which accepts`std::ranges::range_value_t` of `Range`, and `std::ranges::range_value_t` of `Range`, and returns a `bool`. Set to `std::ranges::equal_to` by default
### Parameters
- `range` - A `Range` constant reference
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- A `bool`, whether or not the passed range is a palindrome

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/algorithms/isPalindrome.hpp>

int main() {
	std::string value = "racecar";

	std::cout
		<< std::boolalpha
		<< xieite::algorithms::isPalindrome(std::begin(value), std::end(value))
		<< '\n';
}
```
Output:
```
true
```
