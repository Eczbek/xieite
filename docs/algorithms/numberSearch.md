# [xieite](../xieite.md)::[algorithms](../algorithms.md)::numberSearch
Defined in header [<xieite/algorithms/numberSearch.hpp>](../../include/xieite/algorithms/numberSearch.hpp)

&nbsp;

Finds the lowest numerical value which, if passed to the provided callback, will return `true`. Will automatically determine minimum and maximum limits if they are not given. The callback **must** be logically equaivalent to `(x >= y)`, where `x` is the callback argument and `y` is the desired limit. See example.

&nbsp;

&nbsp;

## Synopses

&nbsp;

> ```cpp
> template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functable<bool(Arithmetic)> Functable>
> [[nodiscard]]
> constexpr Arithmetic numberSearch(const Functable& selector, Arithmetic minimum, Arithmetic maximum);
> ```
> #### Template parameters
> - `Arithmetic`, satisfying `xieite::concepts::Arithmetic`
> - `Functable`, satisfying `xieite::concepts::Functable` of a function type which accepts an `Arithmetic` and returns a `bool`
> #### Function parameters
> - `selector`, reference to a constant `Functable`
> - `minimum`, an `Arithmetic`
> - `maxumum`, an `Arithmetic`
> #### Return type
> - `Arithmetic`
> #### Specifiers
> - `constexpr`
> - `inline`, implicit
> #### Attributes
> - `nodiscard`

&nbsp;

> ```cpp
> template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functable<bool(Arithmetic)> Functable>
> [[nodiscard]]
> constexpr Arithmetic numberSearch(const Functable& selector);
> ```
> #### Template parameters
> - `Arithmetic`, satisfying `xieite::concepts::Arithmetic`
> - `Functable`, satisfying `xieite::concepts::Functable` of a function type which accepts an `Arithmetic` and returns a `bool`
> #### Function parameters
> - `selector`, reference to a constant `Functable`
> #### Return type
> - `Arithmetic`
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
> #include <xieite/algorithms/numberSearch.hpp>
> 
> bool checkCollision(double x) {
>     return x < 10;
> }
> 
> int main() {
>     std::cout << xieite::algorithms::numberSearch([](double x) {
>         return !checkCollision(x);
>     }) << '\n';
> }
> ```
> Output:
> ```
> 10
> ```
