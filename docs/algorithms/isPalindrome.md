# gcufl::algorithms::isPalindrome
Declared in `<gcufl/algorithms/isPalindrome.hpp>`
```cpp
template<std::forward_iterator I>
bool isPalindrome(I begin, I end, const std::function<bool(const typename std::iterator_traits<I>::value_type, const typename std::iterator_traits<I>::value_type)>& comparator = std::equal_to<const typename std::iterator_traits<I>::value_type>()) noexcept;
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
