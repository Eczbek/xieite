# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:palindrome
Defined in header [<xieite/algorithms/palindrome.hpp>](../../../include/xieite/algorithms/palindrome.hpp)

&nbsp;

## Description
Checks if a range is the same backwards as it is forwards, or if an integer can be reversed while remaining the same value.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Functor = std::ranges::equal_to>
[[nodiscard]] constexpr bool palindrome(const Range& range, const Functor& comparator = Functor())
noexcept(xieite::concepts::NoThrowInvocable<Functor, std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>>);
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr bool palindrome(Integer value, std::size_t base = 10) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/algorithms/palindrome.hpp>

int main() {
    std::string string1 = "racecar";
    std::string string2 = "world";
    int integer1 = 12321;
    int integer2 = 12345;

    std::cout
        << std::boolalpha
        << xieite::algorithms::palindrome(string1) << '\n'
        << xieite::algorithms::palindrome(string2) << '\n'
        << xieite::algorithms::palindrome(integer1) << '\n'
        << xieite::algorithms::palindrome(integer2) << '\n';
}
```
Output:
```
true
false
true
false
```
