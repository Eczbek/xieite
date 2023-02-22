# xieite::algorithms::isPalindrome
Defined in header `<xieite/algorithms/isPalindrome.hpp>`

<br/>

Checks if an iterable is the same backwards as it is forwards. Uses `std::equal_to` as the default comparator.

<br/><br/>

## Declaration
```cpp
template<std::forward_iterator I, xieite::concepts::Comparator<typename std::iterator_traits<I>::value_type> C = std::equal_to<typename std::iterator_traits<I>::value_type>>
[[nodiscard]]
constexpr bool isPalindrome(I begin, I end, F&& comparator = C()) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::boolalpha, std::cout
#include <string> // std::string
#include <xieite/algorithms/isPalindrome.hpp>

int main() {
	std::string value = "racecar";
	std::cout << std::boolalpha << xieite::algorithms::isPalindrome(value.begin(), value.end()) << '\n';
}
```
Output:
```
true
```
