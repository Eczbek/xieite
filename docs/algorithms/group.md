# [xieite](../xieite.md)::[algorithms](../algorithms.md)::group
Defined in header [<xieite/algorithms/group.hpp>](../../include/xieite/algorithms/group.hpp)

&nbsp;

Groups elements of a `std::vector` into a `std::unordered_map`, of which the keys' type depends on the return type of the callback provided.

&nbsp;

&nbsp;

## Synopses

&nbsp;

> ```cpp
> template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>> Callback>
> [[nodiscard]]
> inline std::unordered_map<std::invoke_result_t<Callback(std::ranges::range_value_t<Range>)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Callback& callback);
> ```
> #### Template parameters
> - `Range`, satisfying `std::ranges::range`
> - `Callback`, satisfying `std::invocable` of `std::ranges::range_value_t` of `Range`
> #### Function parameters
> - `range`, reference to a constant `Range`
> - `callback`, reference to a constant `Callback`
> #### Return type
> - `std::unordered_map` of (`std::invoke_result_t` of `Callback` taking `std::ranges::range_value_t` of `Range`) and `std::vector` of `std::ranges::range_value_t` of `Range`
> #### Specifiers
> - `inline`
> #### Attributes
> - `nodiscard`

&nbsp;

> ```cpp
> template<std::ranges::range Range, std::invocable<std::ranges::range_value_t<Range>, std::size_t> Callback>
> [[nodiscard]]
> inline std::unordered_map<std::invoke_result_t<Callback(std::ranges::range_value_t<Range>, std::size_t)>, std::vector<std::ranges::range_value_t<Range>>> group(const Range& range, const Callback& callback);
> ```
> #### Template parameters
> - `Range`, satisfying `std::ranges::range`
> - `Callback`, satisfying `std::invocable` of (`std::ranges::range_value_t` of `Range`) and `std::size_t`
> #### Function parameters
> - `range`, reference to a constant `Range`
> - `callback`, reference to a constant `Callback`
> #### Return type
> - `std::unordered_map` of (`std::invoke_result_t` of `Callback` taking ((`std::ranges::range_value_t` of `Range`) and `std::size_t`) and `std::vector` of `std::ranges::range_value_t` of `Range`
> #### Specifiers
> - `inline`
> #### Attributes
>- `nodiscard`

&nbsp;

&nbsp;

## Example
> ```cpp
> #include <iostream>
> #include <unordered_map>
> #include <vector>
> #include <xieite/algorithms/group.hpp>
> 
> int main() {
>     std::vector<int> values { 1, 2, 3, 4, 5 };
> 
>     auto callback = [](int value) {
>         return value % 2;
>     };
> 
>     std::unordered_map<bool, std::vector<int>> groups = xieite::algorithms::group(values, callback);
> 
>     std::cout << "true: ";
>     for (int value : groups[true]) {
>         std::cout << value << ' ';
>     }
>     std::cout << "\nfalse: ";
>     for (int value : groups[false]) {
>         std::cout << value << ' ';
>     }
>     std::cout << '\n';
> }
> ```
> Output:
> ```
> true: 1 3 5
> false: 2 4
> ```
