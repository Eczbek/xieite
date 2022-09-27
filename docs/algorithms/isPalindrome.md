# gcufl::algorithms::isPalindrome
Declared in `<gcufl/algorithms/isPalindrome.hpp>`
```cpp
template<std::forward_iterator I, gcufl::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
constexpr bool isPalindrome(I begin, I end, const F& comparator) noexcept;

template<std::forward_iterator I>
constexpr bool isPalindrome(const I begin, const I end) noexcept;
```
Checks if an iterable is the same backwards as it is forwards.
## Example
```cpp
#include <gcufl/algorithms/isPalindrome.hpp>
#include <iostream>
#include <string>

int main() {
	std::string value = "racecar";
	std::cout << std::boolalpha << gcufl::algorithms::isPalindrome(value.begin(), value.end()) << '\n';
}
```
Output:
```
true
```
