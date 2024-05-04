# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:memoize\<\>\(\)
Defined in header [<xieite/functors/memoize.hpp>](../../../include/xieite/functors/memoize.hpp)

&nbsp;

## Description
Memo-izes a function call and returns its output immediately on subsequent executions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename... Arguments_, std::invocable<Arguments_...> Functor_>
std::invoke_result_t<Functor_, Arguments_...> memoize(Functor_ functor, const Arguments_&... arguments)
noexcept(xieite::concepts::NoThrowInvocable<Functor_, Arguments_...>);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/memoize.hpp"

int add(int x, int y) {
    std::print("{} + {} = ", x, y);
    return x + y;
}

int multiply(int x, int y) {
    std::print("{} * {} = ", x, y);
    return x * y;
}

auto subtract = [](int x, int y) {
    std::print("{} - {} = ", x, y);
    return x - y;
};

int main() {
    std::println("add(1, 2) = ", xieite::functors::memoize(add, 1, 2));
    std::println("add(1, 2) = ", xieite::functors::memoize(add, 1, 2));
    std::println("multiply(3, 4) = ", xieite::functors::memoize(multiply, 3, 4));
    std::println("multiply(3, 4) = ", xieite::functors::memoize(multiply, 3, 4));
    std::println("subtract(5, 6) = ", xieite::functors::memoize(subtract, 5, 6));
    std::println("subtract(5, 6) = ", xieite::functors::memoize(subtract, 5, 6));
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
