# [`xieite`](../../README.md)`::`[`algorithms`](../../docs/algorithms.md)`::isPalindrome`
Defined in header [`<xieite/algorithms/isPalindrome.hpp>`](../../include/xieite/algorithms/isPalindrome.hpp)

<br/>

Checks if an iterable is the same backwards as it is forwards. Uses `std::equal_to` as the default comparator.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<std::forward_iterator Iterator, xieite::concepts::CallbackComparator<typename std::iterator_traits<Iterator>::value_type> Callback = std::equal_to<typename std::iterator_traits<Iterator>::value_type>>
[[nodiscard]]
constexpr bool isPalindrome(Iterator begin, Iterator end, Callback&& comparator = Callback()) noexcept;
```
### Template parameters
- `Iterator` - An iterator type, satisfying `std::forward_iterator`
- `Callback` - A callback type, satisfying `xieite::concepts::CallbackComparator` of `Iterator`'s value type, set to `std::equal_to` of `Iterator`'s value type by default
### Parameters
- `begin` - An `Iterator` copy which points to the beginning of an iterable
- `end` - An `Iterator` copy which points to the end of the same iterable
- `comparator` - A `Callback` right-value reference, default-constructed by default
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
- [`xieite::concepts::CallbackComparator`](../../docs/concepts/CallbackComparator.md)
