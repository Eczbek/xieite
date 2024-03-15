# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:isPalindrome\(\)
Defined in header [<xieite/algorithms/is_palindrome.hpp>](../../../include/xieite/algorithms/is_palindrome.hpp)

&nbsp;

## Description
Checks if a range is the same backwards as it is forwards, or if an integer can be reversed while remaining the same value. Integer palindrome checker does not yet handle negative radices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
[[nodiscard]] constexpr bool isPalindrome(Range&& range, Functor&& comparator = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>>);
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr bool isPalindrome(Integer value, Integer radix = 10) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/algorithms/is_palindrome.hpp"

int main() {
    std::string string1 = "racecar";
    std::string string2 = "world";
    int integer1 = 12321;
    int integer2 = 12345;

    std::println("{}", xieite::algorithms::isPalindrome(string1));
    std::println("{}", xieite::algorithms::isPalindrome(string2));
    std::println("{}", xieite::algorithms::isPalindrome(integer1));
    std::println("{}", xieite::algorithms::isPalindrome(integer2));
}
```
Output:
```
true
false
true
false
```
