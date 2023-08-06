# [xieite](../xieite.md)::[algorithms](../algorithms.md)::count
Defined in header [<xieite/algorithms/count.hpp>](../../include/xieite/algorithms/count.hpp)

&nbsp;

Counts and returns the number of arguments passed.

&nbsp;

&nbsp;

## Synopsis
> ```cpp
> template<typename... Values>
> [[nodiscard]]
> constexpr std::size_t count(const Values&... values) noexcept;
> ```
> #### Template parameters
> - `Values`, any types
> #### Function parameters
> - `values`, references to constant `Values`
> #### Return type
> - `std::size_t`
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
> #include <xieite/algorithms/count.hpp>
> 
> int main() {
>     std::cout << xieite::algorithms::count(1, 0.4, 'e', "aaa") << '\n';
> }
> ```
> Output:
> ```
> 4
> ```
