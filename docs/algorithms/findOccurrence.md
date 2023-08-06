# [xieite](../xieite.md)::[algorithms](../algorithms.md)::findOccurrence
Defined in header [<xieite/algorithms/findOccurrence.hpp>](../../include/xieite/algorithms/findOccurrence.hpp)

&nbsp;

Finds a specific occurrence of a value in a range and returns an iterator pointing to it or the end if it is not found.

&nbsp;

&nbsp;

## Synopsis
> ```cpp
> template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Callback = std::ranges::equal_to>
> [[nodiscard]]
> constexpr std::ranges::const_iterator_t<const Range&> findOccurrence(const Range& range, std::ranges::range_const_reference_t<Range> value, std::size_t count, const Callback& comparator = Callback());
> ```
> #### Template parameters
> - `Range`, satisfying `std::ranges::range`
> - `Callback`, satisfying `xieite::concepts::Functable` of a function pointer which accepts two of `std::ranges::range_value_t` of `Range` and returns a `bool`, set to `std::ranges::equal_to` by default
> #### Function parameters
> - `range`, reference to a constant `Range`
> - `value`, a `std::ranges::range_const_reference_t` of `Range`
> - `count`, a `std::size_t`
> - `comparator`, reference to a constant `Callback`, default-constructed by default
> #### Return type
> - `std::ranges::const_iterator_t` of reference to a constant `Range`, pointing to the specified value occurrence, or to `std::ranges::end(range)` if it is not found
> #### Specifiers
> - `constexpr`
> - `inline`, implicit
> #### Attributes
> - `nodiscard`

&nbsp;

&nbsp;

## Example
> ```cpp
> #include <iostream>
> #include <iterator>
> #include <vector>
> #include <xieite/algorithms/findOccurrence.hpp>
> 
> int main() {
>     std::vector<int> values { 1, 2, 1, 3, 1, 4, 1 };
>     //                        0     1     2     3
> 
>     auto result = xieite::algorithms::findOccurrence(values, 1, 3);
> 
>     std::cout << std::ranges::distance(values.begin(), result) << '\n';
> }
> ```
> Output:
> ```
> 6
> ```
