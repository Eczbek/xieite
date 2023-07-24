# [xieite](../xieite.md)::[algorithms](../algorithms.md)::isPalindrome
Defined in header [<xieite/algorithms/isPalindrome.hpp>](../../include/xieite/algorithms/isPalindrome.hpp)

<br/>

Checks if a range or an integral is the same backwards as it is forwards

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr bool isPalindrome(const Range& range, const Callback& comparator = Callback());
```
### Template parameters
- `Range` - The range type satisfying `std::ranges::range`
- `Callback` - A callback type satisfying `xieite::concepts::Functable` which accepts`std::ranges::range_value_t` of `Range`, and `std::ranges::range_value_t` of `Range`, and returns a `bool`. Set to `std::ranges::equal_to` by default
### Parameters
- `range` - A `Range` constant reference
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- A `bool`, whether or not the passed range is a palindrome

<br/><br/>

```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr bool isPalindrome(const Integral value, const std::size_t base = 10) noexcept;
```
### Template parameters
- `Integral` - An integral type satisfying `std::integral`
### Parameters
- `value` - An `Integral`
- `base` - A `std::size_t`, set to `10` by default
### Return value
- A `bool`, whether or not `value` is a palindrome

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
		<< xieite::algorithms::isPalindrome(value) << '\n';
}
```
Output:
```
true
```
