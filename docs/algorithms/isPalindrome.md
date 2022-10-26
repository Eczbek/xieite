# xieite::algorithms::isPalindrome
Declared in `<xieite/algorithms/isPalindrome.hpp>`
```cpp
template<std::forward_iterator I, xieite::concepts::Comparator<const typename std::iterator_traits<I>::value_type> F>
[[nodiscard]]
constexpr bool isPalindrome(I begin, I end, const F& comparator) noexcept;

template<std::forward_iterator I>
[[nodiscard]]
constexpr bool isPalindrome(const I begin, const I end) noexcept;
```
Checks if an iterable is the same backwards as it is forwards.
## Example
```cpp
#include <xieite/algorithms/isPalindrome.hpp>
#include <iostream>
#include <string>

int main() {
	std::string value = "racecar";
	std::cout << std::boolalpha << xieite::algorithms::isPalindrome(value.begin(), value.end()) << '\n';
}
```
Output:
```
true
```
