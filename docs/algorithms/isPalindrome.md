# [xieite](../xieite.md)::[algorithms](../algorithms.md)::isPalindrome
Defined in header [<xieite/algorithms/isPalindrome.hpp>](../../include/xieite/algorithms/isPalindrome.hpp)

&nbsp;

Checks if a range or an integer is the same backwards as it is forwards.

&nbsp;

&nbsp;

## Synopses

&nbsp;

> ```cpp
> template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
> [[nodiscard]]
> constexpr bool isPalindrome(const Range& range, const Callback& comparator = Callback());
> ```
> #### Template parameters
> - `Range`, satisfying `std::ranges::range`
> - `Callback`, satisfying `xieite::concepts::Functable` of a function type which accepts two of `std::ranges::range_value_t` of `Range` and returns a `bool`, set to `std::ranges::equal_to` by default
> #### Function parameters
> - `range`, reference to a constant `Range`
> - `comparator`, reference to a constant `Callback`, default-constructed by default
> #### Return type
> - `bool`
> #### Specifiers
> - `constexpr`
> - `inline`, implicit
> #### Attributes
> - `nodiscard`

&nbsp;

> ```cpp
> template<std::integral Integer>
> [[nodiscard]]
> constexpr bool isPalindrome(const Integer value, const std::size_t base = 10) noexcept;
> ```
> #### Template parameters
> - `Integer`, satisfying `std::integral`
> #### Function parameters
> - `value`, an `Integer`
> - `base`, a `std::size_t`, set to `10` by default
> #### Return type
> - `bool`
> #### Specifiers
> - `constexpr`
> - `inline`, implicit
> - `noexcept`
> #### Attributes
> - `nodiscard`

&nbsp;

&nbsp;

## Example
> ```cpp
> #include <iostream>
> #include <string>
> #include <xieite/algorithms/isPalindrome.hpp>
> 
> int main() {
>     std::string string1 = "racecar";
>     std::string string2 = "world";
>     int integer1 = 12321;
>     int integer2 = 12345;
> 
>     std::cout
>         << std::boolalpha
>         << xieite::algorithms::isPalindrome(string1) << '\n'
>         << xieite::algorithms::isPalindrome(string2) << '\n'
>         << xieite::algorithms::isPalindrome(integer1) << '\n'
>         << xieite::algorithms::isPalindrome(integer2) << '\n';
> }
> ```
> Output:
> ```
> true
> false
> true
> false
> ```
