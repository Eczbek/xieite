# [xieite](../../xieite.md)\:\:[algorithms](../../algorithms.md)\:\:numberSearch\<\>\(\)
Defined in header [<xieite/algorithms/number_search.hpp>](../../../include/xieite/algorithms/number_search.hpp)

&nbsp;

## Description
Finds the lowest numerical value which, if passed to the provided callback, will return `true`. Automatically determines minimum and maximum limits if they are not given. The callback must be logically equaivalent to `(x >= y)`, where `x` is the callback argument and `y` is the desired limit.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functor<bool(Arithmetic)> Functor>
[[nodiscard]] constexpr Arithmetic numberSearch(Functor&& selector, Arithmetic minimum, Arithmetic maximum)
noexcept(xieite::concepts::NoThrowInvocable<Functor, Arithmetic>);
```
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Functor<bool(Arithmetic)> Functor>
[[nodiscard]] constexpr Arithmetic numberSearch(Functor&& selector)
noexcept(xieite::concepts::NoThrowInvocable<Functor, Arithmetic>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/algorithms/number_search.hpp"

bool checkCollision(double x) {
    return x < 10;
}

int main() {
    std::println("{}", xieite::algorithms::numberSearch([](double x) -> bool {
        return !checkCollision(x);
    }));;
}
```
Output:
```
10
```
