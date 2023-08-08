# [xieite](../xieite.md)\:\:[algorithms](../algorithms.md)\:\:isPalindrome
Defined in header [<xieite/algorithms/isPalindrome.hpp>](../../include/xieite/algorithms/isPalindrome.hpp)

&nbsp;

## Description
Checks if a range is the same backwards as it is forwards, or if an integer can be reversed while remaining the same value.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
[[nodiscard]]
constexpr bool isPalindrome(const Range& range, const Callback& comparator = Callback());
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr bool isPalindrome(const Integer value, const std::size_t base = 10) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/algorithms/isPalindrome.hpp>

int main() {
    std::string string1 = "racecar";
    std::string string2 = "world";
    int integer1 = 12321;
    int integer2 = 12345;

    std::cout
        << std::boolalpha
        << xieite::algorithms::isPalindrome(string1) << '\n'
        << xieite::algorithms::isPalindrome(string2) << '\n'
        << xieite::algorithms::isPalindrome(integer1) << '\n'
        << xieite::algorithms::isPalindrome(integer2) << '\n';
}
```
Output:
```
true
false
true
false
```
