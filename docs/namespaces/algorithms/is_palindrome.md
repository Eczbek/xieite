# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:isPalindrome\<\>\(\)
Defined in fragment [xieite:algorithms.isPalindrome](../../../src/algorithms/is_palindrome.cpp)

&nbsp;

## Description
Checks if a range is the same backwards as it is forwards, or if an integer can be reversed while remaining the same value. Integer palindrome checker does not yet handle negative radices.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::ranges::forward_range Range, xieite::concepts::Invocable<bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> Functor = std::ranges::equal_to>
requires(std::ranges::sized_range<Range>)
[[nodiscard]] constexpr bool isPalindrome(Range&& range, Functor&& comparator = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, bool(std::ranges::range_reference_t<Range>, std::ranges::range_reference_t<Range>)> && xieite::concepts::NoThrowOperableRange<Range>);
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr bool isPalindrome(Integral value, Integral radix = 10) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
