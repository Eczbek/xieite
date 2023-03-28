# xieite::algorithms::isPalindrome
Defined in header `<xieite/algorithms/isPalindrome.hpp>`

<br/>

Checks if an iterable is the same backwards as it is forwards. Uses `std::equal_to` as the default comparator.

<br/><br/>

## Declarations
```cpp
template<std::forward_iterator Iterator, xieite::concepts::ComparatorCallback<typename std::iterator_traits<Iterator>::value_type> Callback = std::equal_to<typename std::iterator_traits<Iterator>::value_type>>
[[nodiscard]]
constexpr bool isPalindrome(Iterator begin, Iterator end, Callback&& comparator = Callback()) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/algorithms/isPalindrome.hpp>

int main() {
	std::string value = "racecar";
	std::cout << std::boolalpha
		<< xieite::algorithms::isPalindrome(std::begin(value), std::end(value)) << '\n';
}
```
Output:
```
true
```
