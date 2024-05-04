# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:isPalindrome\<\>\(\)
Defined in header [<xieite/algorithms/is_palindrome.hpp>](../../../include/xieite/algorithms/is_palindrome.hpp)

&nbsp;

## Description
Checks if a range is the same backwards as it is forwards, or if an integer can be reversed while remaining the same value. Integer palindrome checker does not yet handle negative radices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::range Range_, xieite::concepts::Functable<bool(std::ranges::range_reference_t<Range_>, std::ranges::range_reference_t<Range_>)> Functor_ = std::ranges::equal_to>
[[nodiscard]] constexpr bool isPalindrome(Range_&& range, Functor_&& comparator = Functor_())
noexcept(xieite::concepts::NoThrowInvocable<Functor_, std::ranges::range_reference_t<Range_>, std::ranges::range_reference_t<Range_>>);
```
#### 2)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr bool isPalindrome(Integral_ value, Integral_ radix = 10) noexcept;
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
