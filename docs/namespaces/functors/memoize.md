# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:memoize
Defined in header [<xieite/functors/memoize.hpp"](../../../include/xieite/functors/memoize.hpp)

&nbsp;

## Description
Memo-izes a function call and returns its output immediately on subsequent executions.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename... Arguments, std::invocable<Arguments...> Functor>
std::invoke_result_t<Functor, Arguments...> memoize(Functor functor, const Arguments&... arguments)
noexcept(xieite::concepts::NoThrowInvocable<Functor, Arguments...>);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/functors/memoize.hpp"

int add(int x, int y) {
    std::cout << x << " + " << y << " = ";
    return x + y;
}

int multiply(int x, int y) {
    std::cout << x << " * " << y << " = ";
    return x * y;
}

auto subtract = [](int x, int y) {
    std::cout << x << " - " << y << " = ";
    return x - y;
};

int main() {
    std::cout
        << "add(1, 2) = " << xieite::functors::memoize(add, 1, 2) << '\n'
        << "add(1, 2) = " << xieite::functors::memoize(add, 1, 2) << '\n'
        << "multiply(3, 4) = " << xieite::functors::memoize(multiply, 3, 4) << '\n'
        << "multiply(3, 4) = " << xieite::functors::memoize(multiply, 3, 4) << '\n'
        << "subtract(5, 6) = " << xieite::functors::memoize(subtract, 5, 6) << '\n'
        << "subtract(5, 6) = " << xieite::functors::memoize(subtract, 5, 6) << '\n';
}
```
Output:
```
add(1, 2) = 1 + 2 = 3
add(1, 2) = 3
multiply(3, 4) = 3 * 4 = 12
multiply(3, 4) = 12
subtract(5, 6) = 5 - 6 = -1
subtract(5, 6) = -1
```
