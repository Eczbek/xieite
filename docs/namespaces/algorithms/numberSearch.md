# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:numberSearch
Defined in header [<xieite/algorithms/numberSearch.hpp>](../../../include/xieite/algorithms/numberSearch.hpp)

&nbsp;

## Description
Finds the lowest numerical value which, if passed to the provided callback, will return `true`. Automatically determines minimum and maximum limits if they are not given. The callback **must** be logically equaivalent to `(x >= y)`, where `x` is the callback argument and `y` is the desired limit.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number, xieite::concepts::Functable<bool(Number)> Functor>
[[nodiscard]] constexpr Number numberSearch(const Functor& selector, Number minimum, Number maximum);
```
#### 2)
```cpp
template<xieite::concepts::Numeric Number, xieite::concepts::Functable<bool(Number)> Functor>
[[nodiscard]] constexpr Number numberSearch(const Functor& selector);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/algorithms/numberSearch.hpp>

bool checkCollision(double x) {
    return x < 10;
}

int main() {
    std::cout << xieite::algorithms::numberSearch([](double x) {
        return !checkCollision(x);
    }) << '\n';
}
```
Output:
```
10
```
