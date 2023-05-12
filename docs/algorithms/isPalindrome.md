# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::isPalindrome`
Defined in header [`<xieite/algorithms/isPalindrome.hpp>`](../../include/xieite/algorithms/isPalindrome.hpp)

<br/>

Checks if an iterable is the same backwards as it is forwards. Uses `std::equal_to` as the default comparator.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<std::forward_iterator Iterator, xieite::concepts::Function<bool(std::iter_value_t<Iterator>, std::iter_value_t<Iterator>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr bool isPalindrome(Iterator begin, std::sentinel_for<Iterator> auto end, const Callback& comparator = Callback());
```
### Template parameters
- `Iterator` - An iterator type, satisfying `std::forward_iterator`
- `Callback` - A callback type, satisfying `xieite::concepts::Function` which accepts two `Iterator` value types and returns a `bool`. Set to `std::ranges::equal_to` by default
### Parameters
- `begin` - An `Iterator` copy which points to the beginning of an iterable
- `end` - An `auto` copy, satisfying `std::sentinel_for` of `Iterator`
- `comparator` - A `Callback` constant reference, default-constructed by default
### Return value
- A `bool`, whether or not the passed iterable is a palindrome

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

<br/><br/>

## See also
- [`xieite::concepts::Function`](../../docs/concepts/Function.md)
